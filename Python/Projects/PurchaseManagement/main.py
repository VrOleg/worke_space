# for run this use virtual inviroment by next comand:
# python3 -m venv /path/to/venv     --- create virtual inviroment
# source /path/to/venv/bin/activate --  activate inviroment
# pip install mysql-connector-python -- innstalll mysql--connnector



from app.DB_Manaer import DatabaseManager

# "host": "localhost",
#     "user": "oleg",
#     "password": "!$Aug1987",
#     "database": "Purchasesdb"

def main():
    db = DatabaseManager("localhost", "oleg", "!$Aug1987", "Purchasesdb")
    if db.connect():
        print("connected to data base")

        # rows = db.GetAllTable("Purchases")
        
        # print("data from Purchases table: ")
        # for row in rows:
        #     print(row)     
        
        # db.DeleteAllTable()    
        
        db.close_connection()
    


if __name__ == "__main__":
    main()