#include <stdio.h>
int main()
{
   
   printf("Hello, World!");
   return 0;
}




void loadImage(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) throw runtime_error("无法打开文件");

        file >> width >> height;
        pixels = vector<vector<int>>(height, vector<int>(width));
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                file >> pixels[i][j];
        
        file.close();
    }