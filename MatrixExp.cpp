const int M = 1e9 + 7;

class Matrix {

    public:
    int n;
    int m;
    vector< vector<int> > v;

    Matrix(int n,int m) : n(n), m(m) {
        v.resize(n, vector<int> (m));
    }

    Matrix(vector<vector<int>> copy) {
        n = copy.size();
        m = copy[0].size();
        v.resize(n, vector<int> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) v[i][j] = copy[i][j];
        }
    }

    Matrix(Matrix *copy) {
        int n = copy->n;
        int m = copy->m;
        v.resize(n, vector<int> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) v[i][j] = copy->v[i][j];
        }
    }


    Matrix operator* (const Matrix &other) {
        assert(this->m == other.n);  // can we ?

        vector<vector<int>> ans(n, vector<int>(other.m, 0));

        for (int i = 0; i < n; i++) {
            for (int col = 0; col < other.m; col++) {
                int matIJ = 0;
                for (int j = 0; j < m; j++) {
                    matIJ += v[i][j] * other.v[j][col];
                    matIJ %= M;
                }
                ans[i][col] = matIJ;
            }
        }

        return Matrix(ans);
    }
    

    void print() {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cout << v[i][j] << " "; cout << "\n";
        }
    }
};
