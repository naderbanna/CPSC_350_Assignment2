#include <string>

class Doughnutmode{
  public:
    Doughnutmode();
    Doughnutmode(std::string inputFile);
    ~Doughnutmode();

    void randomGrid();
    void enterFileGrid();
    void generateGrid();
    void simulate();

  private:
    std::string iFile;
    std::string gridData;
    std::string random_array[125];
    std::string file_array[125];
    std::string curr_grid[14][14];
    std::string next_grid[14][14];
    std::string cell_grid[3][3];
    int row;
    int column;
    int r;
    int c;
    int t;
    int q;
    int worldCount = 1;
    double popD;
    int randNum;
    float randPop;
};
