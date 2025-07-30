class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(0,9):
            for j in range(0,9):
                if board[i][j]>='1' and board[i][j]<='9':
                    for k in range(0,9):
                        if board[i][k]==board[i][j] and k!=j:
                            return False
                        if board[k][j]==board[i][j] and k!=i:
                            return False
                        if board[3*(i/3)+k/3][3*(j/3)+k%3]==board[i][j] and i!=(3*(i/3)+k/3) and j!= (3*(j/3)+k%3):
                            return False
        return True


        
        