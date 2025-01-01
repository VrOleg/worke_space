

class Base:
    def __init__(self):
        print("Base Created")
        self.__Fun()

    def Fun(self):
        print("Public fun run")

    def __Fun(self):
        print("private fun run")
        
        

b1 = Base()

b1.Fun()
b1.__Fun()