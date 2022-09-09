int rows = matrix.length;
    int cols = matrix[0].length;
    boolean[] rowzero = new boolean[rows];
    boolean[] colzero = new boolean[cols];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (matrix[r][c] == 0) {
                rowzero[r] = true;
                colzero[c] = true;
            }
        }
    }
    for (int r = 0; r < rows; r++) {
        if (rowzero[r]) {
            for (int c = 0; c < cols; c++) {
                matrix[r][c] = 0;
            }
        }
    }
    for (int c = 0; c < cols; c++) {
        if (colzero[c]) {
            for (int r = 0; r < rows; r++) {
                matrix[r][c] = 0;
            }
        }
    }