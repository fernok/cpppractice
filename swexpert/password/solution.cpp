#define N 4

typedef struct {
           int hit;
           int miss;
} Result;
 
// API
extern Result query(int guess[]);
 
void doUserImplementation(int guess[]) {
           // Implement a user's implementation function
           //
           // The array of guess[] is a return array that
           // is your guess for what digits[] would be.
           guess[0] = 1;
           guess[1] = 2;
           guess[2] = 3;
           guess[3] = 4;
           Result r = query(guess);
}