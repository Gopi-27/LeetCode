class Spreadsheet {
private:
    vector<vector<int>>A;
public:
    Spreadsheet(int rows) {
        A.resize(rows + 1);
        for(int i = 0; i <= rows; i++){
            A[i].resize(26);
        }
    }
    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        int r = 0;
        for(int i = 1; i < cell.size(); i++){
            r = (r * 10) + (cell[i] - '0');
        }
        A[r][c] = value;
        return;
    }
    void resetCell(string cell) {
        int c = cell[0] - 'A';
        int r = 0;
        for(int i = 1; i < cell.size(); i++){
            r = (r * 10) + (cell[i] - '0');
        }
        A[r][c] = 0;
    }
    int GetCellValue(string& s,int start){
        int c = s[start] - 'A';
        int r = 0;
        for(int i = start + 1; s[i] != '+' && i < s.size(); i++){
            r = (r * 10) + ( s[i] - '0');
        }
        return A[r][c];
    }
    int getValue(string formula) {
        int value1 = 0;
        if(formula[1] >= 'A' && formula[1] <= 'Z'){
            value1 = GetCellValue(formula,1);
        }else {
            for(int i = 1; formula[i] != '+'; i++){
                value1 = (value1 * 10) + (formula[i] - '0');
            }
        }
        int idx = 0;
        for(int i = 0; i < formula.size(); i++){
            if(formula[i] == '+'){
                idx = i;
                break;
            }
        }
        int value2 = 0;
        if(formula[idx + 1] >= 'A' && formula[idx + 1] <= 'Z'){
            value2 = GetCellValue(formula,idx + 1);
        }else{
            for(int i = idx + 1; i < formula.size(); i++){
                value2 = (value2 * 10) + (formula[i] - '0');
            }
        }
        return value1 + value2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */