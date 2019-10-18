def gcd(a, b): 
	if b == 0:
		return a
	return gcd(b, a%b)

def exgcd(a, b, d):
	if b == 0:
		d = a
		x = 1
		y = 0
		return d, x, y
	d, y, x = exgcd(b, a%b, d)
	y = y - x*(a//b)
	return d, x, y

def Calc(x, y):
	if y == 1: 
		return x
	return (x + y - 1) // y

def main():
	n, p, w, d = map(int, input().split(" "))
	g = gcd(d, w)
	
#	print(g)
	if p % g > 0:
		print("-1");
		return
	p = p // g
	w = w // g
	d = d // g
	tmp = 0
	x = 0
	y = 0
	_d, x, y = exgcd(w, d, tmp)
	x = x * p
	y = y * p
#	print(str(x) + " " + str(y))
	if y < 0 :
		add = Calc(-y, w) 
#		print(add)
#		print(d)
		y += add * w
		x -= add * d
#		print(str(x) + " " + str(y))
		if x < 0 or x + y > n:
			print("-1")
		else :
			print(str(x) + " " + str(y) + " " + str(n - x - y))
		return
	
	add = y // w
	y -= add * w
	x += add * d
	if x < 0 or x + y > n :
		print("-1")
	else:
		print(str(x) + " " + str(y) + " " + str(n - x - y))
	return

main()
