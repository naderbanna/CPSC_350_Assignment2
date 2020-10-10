#include <string>

class Mirrormode{
  public:
    Mirrormode();
    Mirrormode(std::string inputFile);
    ~Mirrormode();

    void randomGrid();
    void enterFileGrid();
    void generateGrid();
    void simulate();

  private:
    std::string iFile;
    std::string gridData;
    std::string cell_grid[3][3];
    std::string random_array[125];
    std::string file_array[125];
    std::string curr_grid[14][14];
    std::string next_grid[14][14];
    int row;
    int column;
    int r;
    int c;
    int q;
    int t;
    int worldCount = 1;
    double popD;
    int randNum;
    float randPop;
};
