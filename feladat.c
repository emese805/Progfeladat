#include <stdio.h>

int main() {
    int a,b;
    FILE *infile;
    FILE *outfile;

    if (!(infile = fopen("be.txt", "r"))) { 
        return 1;
    }
    if (!(outfile = fopen("ki.txt", "w"))) {
        fclose(infile);
        return 1;
    }

    fscanf(infile, "%d %d", &a, &b);
    int varosszama=0;
    for (int i = 0; i < b; ++i)
    {
        int varos;
    fscanf(infile, "%d", &varos);
        if(varos<b+1){
            varosszama=varosszama+varos;
        }
        
    }
    fprintf(outfile, "%d",varosszama); 
    
    fprintf(outfile, "\n");

    fclose(infile);
    fclose(outfile);
    return 0;
}