#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include "csv.h"
// #include "libtiff/tiff.h"
#include "libtiff/tiffio.h"

using namespace std;

int main(int argc, char** argv) {
    // Abort if insufficient number of arguments are provided
    if (argc != 2) {
        cout << "Enter a valid dataset name!\nAborting...\n";
        return EXIT_FAILURE;
    }

    string dataset = argv[1];
    string base_url = "./data/celltracking_results/" + dataset + "/";
    string csv_name = "ids.csv";

    string ids = base_url + csv_name;

    vector<string> algorithms;

    // ids.csv exists
    if (filesystem::exists(ids)) {
        io::CSVReader<2> in(ids);
        in.read_header(io::ignore_extra_column, "id", "name");
        int id; string algorithm;
        while(in.read_row(id, algorithm)) {
            algorithms.push_back(algorithm);
        }
    }
    // ids.csv doesn't exist
    else {
        for (const auto &entry : filesystem::directory_iterator(base_url)) {
            if (entry.is_directory()) {
                string entry_path = entry.path();
                string::size_type s = entry_path.find(base_url);
                string algorithm = entry_path.erase(s, base_url.length());
                if (!algorithm.compare("input")) continue;
                algorithms.push_back(algorithm);
            }
        }
    }

    int algo_len = algorithms.size();
    for (int i = 0; i < algo_len; i++) {
        for (int j = i + 1; j < algo_len; j++) {
            string outer_algorithm = algorithms[i];
            string inner_algorithm = algorithms[j];

            // for 01_RES and 02_RES
            for (int k = 1; k <= 2; k++) {
                string write_url = base_url + to_string(i) + "_" + to_string(j) 
                    + "_0" + to_string(k) + "_RES.csv";
                
                fstream fout;
                fout.open(write_url, ios::out | ios::app);

                int tif_count = 0;
                string outer_dirname = base_url + outer_algorithm + "/0" 
                    + to_string(k) + "_RES";
                string inner_dirname = base_url + inner_algorithm + "/0" 
                    + to_string(k) + "_RES";

                // count the number of .tif files in the directory
                for (const auto &entry : filesystem::directory_iterator(outer_dirname)) {
                    string entry_path = entry.path();
                    string extension = entry_path.substr(entry_path.length() - 4);
                    if (!extension.compare(".tif")) tif_count++;
                }
                
                int length = to_string(tif_count).size();
                int denominator = 0;
                int numerator = 0;

                for (int l; l < tif_count; l++) {
                    string tif_name = "/mask" + string(length - to_string(l).size(), '0') 
                        + to_string(l) + ".tif";
                    
                    string outer_tif_name = outer_dirname + tif_name;
                    string inner_tif_name = inner_dirname + tif_name;
                    
                    // if either .tif file doesn't exist, write -1 and continue
                    if (!filesystem::exists(outer_tif_name) || !filesystem::exists(inner_dirname)) {
                        fout << l << ",-1" << endl;
                        continue;
                    }
                    
                    TIFF *outer_tif = TIFFOpen(outer_tif_name.c_str(), "r");
                    TIFF *inner_tif = TIFFOpen(inner_tif_name.c_str(), "r");

                    // do something here
                    // if (!outer_tif) continue;
                    // if (!inner_tif) continue;

                    // uint32 imagelength;
                    // tdata_t outer_buf, inner_buf;
                    // tsize_t outer_line_size = TIFFScanlineSize(outer_tif);
                    // tsize_t inner_line_size = TIFFScanlineSize(inner_tif);
                    // uint32 row;

                    // TIFFGetField(outer_tif, TIFFTAG_IMAGELENGTH, &imagelength);

                    // outer_buf = _TIFFmalloc(outer_line_size);
                    // inner_buf = _TIFFmalloc(inner_line_size);

                    // for (row = 0; row < imagelength; row++) {
                    //     TIFFReadScanline(outer_tif, outer_buf, row);
                    //     for (uint32 col = 0; col < outer_line_size; col++) {
                    //         // printf("%d\n", outer_buf[col]);
                    //         cout << outer_line_size << endl;
                    //     }
                    // }

                    // _TIFFfree(outer_buf);
                    // _TIFFfree(inner_buf);

                    TIFFClose(outer_tif);
                    TIFFClose(inner_tif);
                }
            }
        }
    }
    

    return 0;
}