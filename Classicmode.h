#include <string>

class Classicmode{
  public:
    Classicmode();
    Classicmode(std::string inputFile);
    ~Classicmode();

    void randomGrid();
    void enterFileGrid();
    void generateGrid();
    void simulate();

  private:
    std::string iFile;
    std::string gridData;
    std::string random_array[14][14];
    std::string file_array[125];
    std::string curr_grid[14][14];
    std::string next_grid[14][14];
    int row;
    int column;
    int r;
    int c;
    int worldCount = 1;
    //std::string file_array[];
    //int curr_grid[][];
    //int next_grid[][];





};
