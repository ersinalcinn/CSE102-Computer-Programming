#include <stdio.h> 
long int Sizeof_find(char file_name[]);
struct count_char()
{
    int count=1;
    char val;
};
int main() 
{ 
    char file_1[] = { "encoded.dat" }; 
    char file_2[] = { "decoded.txt" }; 
    long int size1 = Sizeof_find(file_1); 
    long int size2 = Sizeof_find(file_2); 
    if (size1 != -1) 
    {

        printf("Size of the %s is %ld bytes \n", file_1,size1);
        printf("Size of the %s is %ld bytes \n", file_2,size2);  
        if (size1>size2)
        {
            printf("Calculation of the file size difference between encryption and decryption : %ld \n",size1-size2); 
        }
        else
        {
            printf("Calculation of the file size difference between encryption and decryption : %ld \n",size2-size1); 
        }
    }
    
    return 0; 
}
long int Sizeof_find(char file_name[]) 
{ 
    FILE* ptr = fopen(file_name, "r");  
    fseek(ptr, 0L, SEEK_END); // checking if the file exist or not 
    long int size = ftell(ptr); // calculating the size of the file
    fclose(ptr); 
    return size; 
} 