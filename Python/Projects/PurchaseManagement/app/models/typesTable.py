from datetime import datetime

class TypeTable:
    TABLE_NAME = "Items_Type"
    CREAT_STATEMENT = """
    CREATE TABLE IF NOT EXISTS Items_Type(
        Id INT AUTO_INCREMENT PRIMARY KEY,
        Type_Name VARCHAR(255) NOT NULL,
        Update_date DATETIME
    )
    """
    default_query = f"INSERT INTO Items_Type (Type_Name, Update_date) VALUES ('Unknown', '{datetime.now()}')" 
    
    @staticmethod
    def get_create_statement():
        return TypeTable.CREAT_STATEMENT
    