import numpy as np

def f(x):
    return x ** 2

def L(Pn):
    output = 0
    for x in range(len(Pn) -1 ):
        output += f(Pn[x]) * (Pn[x+1] - Pn[x])
    return output    



def U(Pn):
    output = 0
    for x in range(len(Pn) -1 ):
        output += f(Pn[x+1]) * (Pn[x+1] - Pn[x])
    return output    



def main():
    #User input 
    a = int(input("Insert a:")) #Type cast from string to int
    b = int(input("Insert b:")) #Type cast from string to int
    dx = float(input("Insert dx:")) #Type cast from string to decimal
    Pn = np.arange(a,b+dx,dx) #calculating partition vector
    #print(Pn) Debug
    #print("U",U(Pn))
    #print("L",L(Pn))

    f = open("output_python.txt", "a")
    f.write("\n"+"a: "+str(a)+" b: "+str(b)+" dx:"+str(dx)+" U:"+str(U(Pn))+" L"+str(L(Pn))+" U-L"+str(U(Pn)-L(Pn)))
    f.close()



if __name__ == "__main__":
    main()
