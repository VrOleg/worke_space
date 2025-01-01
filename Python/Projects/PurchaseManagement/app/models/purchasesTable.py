

class PurchasesTable:
    TABLE_NAME = "Purchases"
    CREATE_STATEMENT = """
    CREATE TABLE IF NOT EXISTS Purchases(
        Id INT AUTO_INCREMENT PRIMARY KEY,
        Item_Name VARCHAR(255) NOT NULL,
        Quantity INT,
        Price_Per_One DECIMAL(10, 2),
        Total_Price DECIMAL(10, 2),
        type_id INT DEFAULT 0,
        Buy_Data DATETIME,
        Modification_Data DATETIME NOT NULL,
        FOREIGN KEY (type_id) REFERENCES Items_Type(id)
        )
        """
    
    @staticmethod
    def get_create_statement():
        return PurchasesTable.CREATE_STATEMENT
    
    