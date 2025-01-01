
def print_board(board):
    print()
    for i, row in enumerate(board):
        
        row_str = " | ".join(f"{value:>2}"for value in row)
        print(row_str)
        
        if i != len(board) - 1:
            print('-' * (len(board) * 4 + 1)) 

def move(turn, board):
    rows = len(board)
    cols = len(board[0])
    while True:
        player_input = input(f"{turn}'s turn, please select the cell: ")
        if player_input.isdigit():
            if 0 < int(player_input) <= rows * cols:
                row = (int(player_input) - 1) // cols
                col = (int(player_input) - 1) % cols
            
                if board[row][col] not in ["X","O"]:
                    board[row][col] = turn               
                    break
                else:
                    print("This cell is not free! ")
                    continue
        
        print("Invalid input, please try again! ")

def generate_win_positions(size):
    win_pos = []
    
    for i in range(size):
        win_pos.append([(i, j) for j in range(size)]) # add Rows
        win_pos.append([(j, i) for j in range(size)]) # add Columns

    win_pos.append([(i, i) for i in range(size)]) # add diaonal from top-left to bottom-right
    win_pos.append([(i, size - i - 1) for i in range(size)]) # add diaonal from top-right to bottom-left

    return win_pos

def check_win(turn, board):
    
    win_pos = generate_win_positions(len(board))
    
    for pos in win_pos:
        if all(board[row][col] == turn for row,col in pos):
            return True
    return False

def get_board():
    while True:
        size = input("please enter the size of board (between 1 and 20): ")
        if size.isdigit():
            size = int(size)
            if 0 < size <= 20 :
                board = [[str(i * size + j + 1) for j in range(size)] for i in range(size)]
                return board
        print("size must be positive integer number!")

def __main__():
    turn = 'X'
    
    win = False
    new_game = True

    print("Welcome to Tic-Tac-Toe!")
    print("Players take turns selecting a cell to place their marker (X or O).")
    print("The first player to align markers horizontally, vertically, or diagonally wins!")
    
    while new_game:
        
        board = get_board()
        board_size = len(board) ** 2    
        round = 0
        print_board(board)
        
        while round < board_size:
            print()
            move(turn,board)
            print_board(board)
            win = check_win(turn, board)
            if win:
                print()
                print(f"*********** {turn} Win this game!!! ***********")
                break
            
            if turn == 'X':
                turn = 'O'
            else:
                turn = 'X'
            
            round += 1   
        
        if not win:
            print("this game finished with draw!!!")
        
        user_input = input("Do you want to play again? (y/n): ")
        if user_input.lower() == 'n':
            new_game = False
__main__()