def kesisim(l1,l2):
	x1 = l1[0][0]
	y1 = l1[0][1]
	x2 = l1[1][0]
	y2 = l1[1][1]
	x3 = l2[0][0]
	y3 = l2[0][1]
	x4 = l2[1][0]
	y4 = l2[1][1]
	if(not esit(x1,x2) and not esit(x3,x4)):
		m1 = (y2-y1)/(x2-x1)
		m2 = (y4-y3)/(x4-x3)
		n1 = y1-m1*x1
		n2 = y3-m2*x3
		if m2 == m1 and n2 != n1:
			return (-0.23,-0.23)
		if m2 == m1:
			if x1<=x3<=x2 or x1>=x3>=x2:
				x = x3
			elif x1<=x4<=x2 or x1>=x4>=x2:
				x = x4
			elif x3<=x1<=x4 or x3>=x1>=x4:
				x = x1
			elif x3<=x2<=x4 or x3>=x2>=x4:
				x = x2
			else:
				return (-0.23,-0.23)
		else:
			x = (n2-n1)/(m1-m2)
		if((x1<=x<=x2) or (x1>=x>=x2)) and ((x3<=x<=x4) or (x3>=x>=x4)):
			y = m1*x+n1
			return (x,y)
		return (-0.23,-0.23)
	if esit(x1,x2) and esit(x3,x4):
		if not esit(x1,x3): return (-0.23,-0.23);
		if y3<=y1<=y4 or y3>=y1>=y4:
			return (x1,y1)
		if y3<=y2<=y4 or y3>=y2>=y4:
			return (x1,y2)
		if y1<=y3<=y2 or y1>=y3>=y2:
			return (x1,y3)
		if y1<=y4<=y2 or y1>=y4>=y2:
			return (x1,y4)
		return (-0.23,-0.23)
	if esit(x1,x2):
		m2 = (y4-y3)/(x4-x3)
		n2 = y4-m2*x4
		y = m2*x1+n2
		if (y1<=y<=y2 or y1>=y>=y2) and (y3<=y<=y4 or y3>=y>=y4) and (x3<=x1<=x4 or x3>=x1>=x4):
			return (x1,y)
		return (-0.23,-0.23)
	if esit(x3,x4):
		m2 = (y2-y1)/(x2-x1)
		n2 = y2-m2*x2
		y = m2*x3+n2
		if (y1<=y<=y2 or y1>=y>=y2) and (y3<=y<=y4 or y3>=y>=y4) and (x1<=x3<=x2 or x1>=x3>=x2):
			return (x3,y)
		return (-0.23,-0.23)

	
def esit(a,b):
	return b-10**-5<a<b+10**-5

def alan(p1,p2,p3):
	return abs((p1[0]*(p2[1]-p3[1])+p2[0]*(p3[1]-p1[1])+p3[0]*(p1[1]-p2[1]))/2)

def inside(pt,e1,e2,e3):
	top = 0;
	top+=alan(pt,e1,e2)
	top+=alan(pt,e1,e3)
	top+=alan(pt,e2,e3)
	return esit(alan(e1,e2,e3),top)

def side(pt,l):
	d = (pt[0]-l[0][0])*(l[1][1]-l[0][1]) - (pt[1]-l[0][1])*(l[1][0]-l[0][0])
	return -1 if d<0 else 1

def konkav(s):
	if side(s[1],(s[0],s[2])) == side(s[3],(s[0],s[2])):
		return 1
	if side(s[2],(s[1],s[3])) == side(s[0],(s[1],s[3])):
		return 2
	if side(s[3],(s[0],s[2])) == side(s[1],(s[0],s[2])):
		return 3
	if side(s[0],(s[3],s[1])) == side(s[2],(s[3],s[1])):
		return 0
	return 4

def insideQuad(pt,s):
	if konkav(s) == 1:
		return inside(pt,s[0],s[1],s[3]) or inside(pt,s[1],s[2],s[3])
	if konkav(s) == 2:
		return inside(pt,s[0],s[1],s[2]) or inside(pt,s[0],s[2],s[3])
	if konkav(s) == 3:
		return inside(pt,s[1],s[2],s[0]) or inside(pt,s[2],s[3],s[0])
	if konkav(s) == 4:
		return inside(pt,s[0],s[1],s[2]) or inside(pt,s[0],s[2],s[3])
	return False

def minority_shape_intersect(s1,s2):
	lines1=[]
	lines2=[]
	edges = []
	if len(s1) == 3:
		lines1 = [(s1[0],s1[1]),(s1[1],s1[2]),(s1[2],s1[0])]
	else:
		lines1 = [(s1[0],s1[1]),(s1[1],s1[2]),(s1[2],s1[3]),(s1[3],s1[0])]
	if len(s2) == 3:
		lines2 = [(s2[0],s2[1]),(s2[1],s2[2]),(s2[2],s2[0])]
	else:
		lines2 = [(s2[0],s2[1]),(s2[1],s2[2]),(s2[2],s2[3]),(s2[3],s2[0])]
	for i in range(0,len(lines1)):
		for j in range(0,len(lines2)):
			a = kesisim(lines1[i],lines2[j])
			if not esit(a[0],-0.23):
				if edges.count(a) == 0:
					edges.append(a)
	if len(s2) == 3:
		for i in range(0,len(s1)):
			if inside(s1[i],s2[0],s2[1],s2[2]) and edges.count(s1[i]) == 0:
				edges.append(s1[i])
	if len(s1) == 3:
		for i in range(0,len(s2)):
			if inside(s2[i],s1[0],s1[1],s1[2]) and edges.count(s2[i]) == 0:
				edges.append(s2[i])
	if len(s1) == 4:
		for i in range(0,len(s2)):
			if insideQuad(s2[i],s1) and edges.count(s2[i]) == 0:
				edges.append(s2[i])
	if len(s2) == 4:
		for i in range(0,len(s1)):
			if insideQuad(s1[i],s2) and edges.count(s1[i]) == 0:
				edges.append(s1[i])
	return edges
