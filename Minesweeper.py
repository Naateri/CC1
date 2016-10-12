import random 
import sys
import os
#mat1 = []
#Visual
#mat2 = []
#Bombas
#mat3 = []
#Numeritos

def inputnrocol(mensaje):
	f = input(mensaje)
	if f <= 0:
		return inputnrocol("Ingrese un numero valido: ")
	return f
#c = input("Ingrese el numero de columnas: ")
def inputnromina(mensaje, f):
	m = input(mensaje)
	if m >= f*f or m<=0:
		return inputnromina("Ingrese un numero valido: ", f)
	return m
def crearMatriz(f,append):
	mat = []
	for columnas in range(f):
		l = []
		for filas in range(f):
			l.append(append)
		mat.append(l)
	return mat
	
def bombitas(mat,mina):
	#crearMatriz(f,mat)
	for a in range(mina):
		h = random.randrange(len(mat))
		k = random.randrange(len(mat))
		mat[h][k] = "*"
	
def contarbombitas(mat, matriz):
	#mat = mat2 = append de bombas, matriz = mat3 = numeritos
	for x in range(len(mat)):
		for y in range(len(mat)):
			c = 0
			if x > 0:
				if y > 0:			
					if matriz[x-1][y-1] == "*":
						c+=1
				if matriz[x-1][y] == "*":
					c+=1
				if y < len(matriz)-1:				
					if matriz[x-1][y+1] == "*":
						c+=1
		
			if x < len(matriz)-1:
				if y>0:
					if matriz[x+1][y-1] == "*":
						c+=1
				if y < len(matriz)-1:
					if matriz[x+1][y+1] == "*":
						c+=1
				if matriz[x+1][y] == "*": 
					c+=1
			if y>0:
				if matriz[x][y-1] == "*":
					c+=1
			if y < len(matriz)-1:
				if matriz[x][y+1] == "*":
					c+=1
			mat[x][y] = c
			if matriz[x][y] == "*":
				mat[x][y] = "*"
				
def imprimeMat(mat):
	for a in range(len(mat)):
		f = ""
		for b in range(len(mat[0])):
			f+=str(mat[a][b])
		print f
		
def pedirCoordenadaX(mat1, mensaje):
	x = input(mensaje)
	if x >= len(mat1):
		return pedirCoordenadaX(mat1, "Introduzca un numero menor a " + str(len(mat1)) + ": ")
	if x < 0:
		return pedirCoordenadaX(mat1, "No se pueden poner numeros negativos. Introduzca un numero valido: ")
	return x
	
def pedirCoordenadaY(mat1, mensaje):
	y = input(mensaje)
	if y >= len(mat1[0]):
		return pedirCoordenadaY(mat1, "Introduzca un numero menor a " + str(len(mat1[0])) + ": ")
	if y < 0:
		return pedirCoordenadaY(mat1, "No se pueden poner numeros negativos. Introduzca un numero valido: ")
	return y
	

def revelar(x, y, mat3, mat1, mat4):
	if mat3[x][y] == "*":
		imprimeMat(mat3)
		sys.exit("Has pisado una mina!! Has perdido.")
	if mat3[x][y] == 0: 
		#mat4[x][y] = "B"	
		if x > 0 and x < len(mat3):
			if y > 0 and mat4[x-1][y-1] == "A":
				mat4[x-1][y-1] = "B"				
				if mat3[x-1][y-1] == "*":
					mat1[x-1][y-1] = "_"
		
				if mat3[x-1][y-1] != "*":
					mat1[x-1][y-1] = mat3[x-1][y-1]
					revelar(x-1, y-1, mat3, mat1, mat4)
						
			if y < len(mat3)-1 and mat4[x-1][y+1] == "A":
				mat4[x-1][y+1] = "B"				
				if mat3[x-1][y+1] == "*":
					mat1[x-1][y+1] = "_"
				if mat3[x-1][y+1] != "*":
					mat1[x-1][y+1] = mat3[x-1][y+1]
					revelar(x-1, y+1, mat3, mat1, mat4)
				
			if mat4[x-1][y] == "A":
				mat4[x-1][y] = "B"
				if mat3[x-1][y] == "*":
					mat1[x+1][y+1] = "_"
				if mat3[x-1][y] != "*":
					mat1[x-1][y] = mat3[x-1][y]
					revelar(x-1, y, mat3, mat1, mat4)
		if x < len(mat3)-1:
			if y>0 and mat4[x+1][y-1] == "A":
				mat4[x+1][y-1] = "B"
				if mat3[x+1][y-1] == "*":
					mat1[x+1][y+1] = "_"
				if mat3[x+1][y-1] != "*":
					mat1[x+1][y-1] = mat3[x+1][y-1]
					revelar(x+1, y-1, mat3, mat1, mat4)
				
			if y < len(mat3)-1 and mat4[x+1][y+1] == "A":
				mat4[x+1][y+1] = "B"	
				if mat3[x+1][y+1] == "*":
					mat1[x+1][y+1] = "_"
				if mat3[x+1][y+1] != "*":
					mat1[x+1][y+1] = mat3[x+1][y+1]
					revelar(x+1, y+1, mat3, mat1, mat4)
			
			if mat4[x+1][y] == "A":
				mat4[x+1][y] = "B"		
				if mat3[x+1][y] == "*":
					mat1[x+1][y] = "_"
				if mat3[x+1][y] != "*":
					mat1[x+1][y] = mat3[x+1][y]
					revelar(x+1, y, mat3, mat1, mat4)
			
		if y>0 and y<len(mat3):
			if mat4[x][y-1] == "A":
				mat4[x][y-1] = "B"
				if mat3[x][y-1] == "*":
					mat1[x][y-1] = "_"
				if mat3[x][y-1] != "*":
					mat1[x][y-1] = mat3[x][y-1]
					revelar(x, y-1, mat3, mat1, mat4)
			
	
		if y < len(mat3)-1:
			if mat4[x][y+1] == "A":
				mat4[x][y+1] = "B"
				if mat3[x][y+1] == "*":
					mat1[x][y+1] = "_" 
				if mat3[x][y+1] != "*":
					mat1[x][y+1] = mat3[x][y+1]
					revelar(x, y+1, mat3, mat1, mat4)
	mat4[x][y] = "B"
	mat1[x][y] = mat3[x][y]
			
	
def minearPregunta():
	asu = raw_input("Desea poner una mina sobre esta posicion? (s/n) ")
	if asu  == "s" or asu == "S":
		return True
	else:
		return False

def contarM(mat1):
	c = 0
	for a in range(len(mat1)):
		for b in range(len(mat1[0])):
			if mat1[a][b] == "M":
				c+=1
	return c
	
def main():
	score = 0
	f = inputnrocol("Inserte el numero de filas y columnas: ")
	m = inputnromina("Inserte el numero de minas: ", f)
	mat1 = crearMatriz(f, "_")
	#visual
	mat2 = crearMatriz(f, "_")
	#bombitas 
	mat3 = crearMatriz(f, "_")
	#numeritos
	mat4 = crearMatriz(f, "A")
	#A = NO PASO POR AQUI, B = PASO POR AQUI
	bombitas(mat2, m)
	contarbombitas(mat3, mat2)
	imprimeMat(mat1)
	#print " "
	#imprimeMat(mat2)
	#print " "
	#imprimeMat(mat3)
	#print " "
	#imprimeMat(mat4)
	#print " "
	while score < m:
		#clear = lambda: os.system('clear')
		#clear()
		x = pedirCoordenadaX(mat1, "Introduce la fila: ")
		y = pedirCoordenadaY(mat1, "Introduce la columna: ")
		asu = minearPregunta()
		if asu:
			if mat1[x][y] == "M":
				mat1[x][y] = "_"
				imprimeMat(mat1)
			else:
				mat1[x][y] = "M"
				if mat3[x][y] == "*":
					score +=1
				imprimeMat(mat1)
		else:
			revelar(x, y, mat3, mat1, mat4)
			imprimeMat(mat1)
	if score==m:
		imprimeMat(mat3)
		sys.exit("Usted ha ganado!")
main()
