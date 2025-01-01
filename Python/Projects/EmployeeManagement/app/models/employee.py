import mysql.connector

con = mysql.connector.connect(
    host='localhost', user="oleg", password='!$Aug1987', database='emp')


# Check if Employee exist in database by id
def check_employee(employee_id):
    # SQL Query to select the employee with match id
    sql = 'SELECT * FROM employees WHERE id=%s'

    # Making cursor buffered to make rowcount method work properly
    cursor = con.cursor(buffered=True)
    data = (employee_id,)

    # Executing the SQL Query
    cursor.execute(sql, data)

    # Fetch the first row to check if employee exists
    employee = cursor.fetchone()

    cursor.close()

    # If employee is found, return True, else return False
    return employee is not None

# Add new Employee
def add_employee():
    Id = input("Enter Employee Id: ")

    if check_employee(Id):
        print("Employee already exists. Please try again.")
        return

    else:
        Name = input("Enter Employee Name: ")
        Post = input("Enter Employee Post: ")
        Salary = input("Enter Employee Salary: ")

        sql = 'INSERT INTO employees (id, name, position, salary) VALUES(%s, %s, %s, %s)'

        data = (Id, Name, Post, Salary)
        cursor = con.cursor()

        try:
            cursor.execute(sql, data)

            con.commit()
            print("Employee added Successfully")

        except mysql.connector.Error as err:
            print(f"Error: {err}")
            con.rollback()

        finally:
            cursor.close()

# Remove Employee
def remove_employee():
    Id = input("Enter Employee Id:")

    if not check_employee(Id):
        print('Employee does not exist. Please try again.')
        return
    
    else:
        sql = 'DELETE FROM employees WHERE id=%s'
        data = (id,)
        cursor = con.cursor()

        try:
            cursor.execute(sql, data)

            con.commit()
            print("Employee Removed Successfully")
        
        except mysql.connector.Error as err:
            print(f"Error: {err}")
            con.rollback()

        finally:
            cursor.close()

def promote_employee():
    Id = input("Enter Employee Id: ")

    if not check_employee(Id):
        print("Employee does not exist. Please try again.")
    
    else:
        try:
            Amount = float(input("Enter increase in Salary: "))

            sql_select = 'SELECT salary FROM employees WHERE id=%s'
            data = (Id,)
            cursor = con.cursor()

            cursor.execute(sql_select, data)
            current_salary = cursor.fetchone()[0]
            new_salary = current_salary + Amount

            sql_update = 'UPDATE employees SET salary=%s WHERE id=%s'
            data_update = (new_salary, Id)

            cursor.execute(sql_update, data_update)

            con.commit()
            print("Employee Promoted Successfully")
        
        except (ValueError, mysql.connector.Error) as e:
            print(f"Error: {e}")
            con.rollback()

        finally:
            cursor.close()

def display_employees():
    try:
        sql = "SELECT * FROM employees"
        cursor = con.cursor()

        cursor.execute(sql)

        employees = cursor.fetchall()

        print(" Id   Name       Post        Salary")
        for employee in employees:
            print(f"{employee[0]}  {employee[1]}  {employee[2]}  {employee[3]}")

    except mysql.connector.Error as err:
        print(f"Error: {err}")
    
    finally:
        cursor.close()

def menu():
    try:
        while True:
            print("\nWelcome to Employee Management Record")
            print("Press:")
            print("1. to Add Employee")
            print("2. to Remove Employee")
            print("3. to Promote Employee")
            print("4. to Display Employee")
            print("5. to Exit")

            ch = input("Enter your choice: ")

            if ch == '1':
                add_employee()
            elif ch == '2':
                remove_employee()
            elif ch == '3':
                promote_employee()
            elif ch == '4':
                display_employees()
            elif ch == '5':
                print("Exiting the program. Goodbye!")
                break
            else:
                print("Invalid Choice! Please try again.")
    finally:
        con.close()

if __name__ == "__main__":
    menu()
