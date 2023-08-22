class Solution {
  public:
    vector<double> myCalculator(double Arr[3][4]) {
           // cofficient = Inverse(Arr)*Arr[][3]  

    // determinant
    double determinant = 0;
    for(int i = 0; i < 3; i++)
        determinant = determinant + (Arr[0][i] * (Arr[1][(i+1)%3] * Arr[2][(i+2)%3] - Arr[1][(i+2)%3] * Arr[2][(i+1)%3]));

    // inverse of matrix
    double inverse_matrix[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)        
            inverse_matrix[i][j]=((Arr[(j+1)%3][(i+1)%3] * Arr[(j+2)%3][(i+2)%3]) - (Arr[(j+1)%3][(i+2)%3] * Arr[(j+2)%3][(i+1)%3]))/ determinant;
        
   
    std::vector<double> coefficient;
    for(int i=0;i<3;i++)
        coefficient.push_back( std::floor(inverse_matrix[i][0]*Arr[0][3] + inverse_matrix[i][1]*Arr[1][3]+ inverse_matrix[i][2]*Arr[2][3]));
    
    return coefficient;
    }
};
