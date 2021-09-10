#include <iostream>
#include <string>

using namespace std;

class Dimension
{
    public:
    Dimension()
    {
        dimId = 0;
    }

    private:
    int dimId;
    shared_ptr<int> p;
};

template <typename Aty_>
class SourceArray
{
    public:
    explicit SourceArray(std::string arrayName)
    {
        arrN_ = arrayName;
    }

    private:
    string arrN_;
};

int main() {
    return 0;
}