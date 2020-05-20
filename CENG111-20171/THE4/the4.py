def parentCheck(node,l,limits):
		i = 0
		#print limits
		#print node.name + " inkiler" + str(l)
		for p in l:
			if l.index(p)==len(l)-1:
				continue
			i = i+1
			top = 0
			for c in p.children:
				top+=c.force
			if top+node.force <= p.force and node.force >= limits[l.index(p)+3]:
				tasi(node,p)
				l[-1].children.remove(node)
				break
		return
		
def tasi(a,b):
	x = commander(a.name,a.force)
	b.children.append(x)
	return
	
def help_ben_solo(H,T):
	t = construct(H)
	h = t.findHeight()
	aim = h-T+1
	cons1(t)
	executeds = cons2(t,aim)
	executed = []
	for e in executeds:
		executed.append(e.name)
	return (convert(t),executed)
	
def cons2(t,n):
	h = t.findHeight()
	executed = []
	for i in xrange(h,n,-1):
		limits = findDepthLimits(t)
		lows = []
		makeDepthList(t,h,lows,1)
		mark = [False]*len(lows)
		max = -1
		ind = 0
		for j in range(0,len(lows)):
			max = -1
			for k in range(0,len(lows)):
				if not mark[k] and (max==-1 or lows[k].force>max):
					ind = k
					max = lows[k].force
			l=[]
			findParent(t,lows[ind],l,limits)
			mark[ind]=True
			limits = findDepthLimits(t)
		executeDepth(t,h,1,executed)
		h=h-1
	return executed

def convert(t):
	l=[t.name,t.force]
	for c in t.children:
		l.append(convert(c))
	return l
	
def findParent(cur,dest,l,limits):
	if cur.name == dest.name:
		parentCheck(dest,l,limits)
		return
	l.append(cur)
	for c in cur.children:
		findParent(c,dest,l,limits)
	l.remove(cur)
	return

def executeDepth(t,n,adim,l):
	if adim==n-1:
		l.extend(t.children)
		t.children = []
		return
	for c in t.children:
		executeDepth(c,n,adim+1,l)
	return
	
def dolas(t,adim,l):
	if t.force < l[adim] or l[adim]==0:
		l[adim] = t.force
	for c in t.children:
		dolas(c,adim+1,l)
	return
	
def findDepthLimits(t):
	h = t.findHeight()
	limits = [0]*(h+1)
	dolas(t,1,limits)
	return limits

def cons1(t):
	flag = True
	h = t.findHeight()
	while flag:
		flag = False
		for i in xrange(h,1,-1):
			lows = []
			pros = []
			makeDepthList(t,i,lows,1)
			makeDepthList(t,i-1,pros,1)
			flag2 = True
			while(flag2):
				flag2 = False
				for k in lows:
					for b in pros:
						if k.force>b.force:
							k.swap(b)
							flag2 = True
							flag = True

def makeDepthList(node,n,l,adim):
	if adim>n:
		return
	if adim==n:
		l.append(node)
	for c in node.children:
		makeDepthList(c,n,l,adim+1)
	return

def construct(n):
	if n==[] or type(n)!=list:
		return False
	com = commander(name(n),force(n))
	for c in children(n):
		chil = construct(c)
		if chil != False:
			com.addChild(chil)
	return com

def name(n):
	return n[0]

def force(n):
	return n[1]

def children(n):
	if len(n)>2: return n[2:]
	return []

class commander:
	children = []
	force = 0
	name = ""
	def __init__(self,name,force):
		self.name = name
		self.force = force
		self.children=[]
		return
	def child(self,a):
		return self.children[a]
	def addChild(self,child):
		self.children.append(child)
		return
	def swap(self,b):
		bf = b.force
		bn = b.name
		b.force = self.force
		b.name = self.name
		self.force = bf
		self.name = bn
		return
	def printCommander(self):
		print "name=" + self.name + " force=" + str(self.force)
		for c in self.children:
			c.printCommander()
		return
	def findHeight(self):
		if self.children == []:
			return 1
		max = 0
		for c in self.children:
			if c.findHeight() > max:
				max = c.findHeight()
		return max+1
	def __str__(self):
		return  self.name
	
#print help_ben_solo(["Ben Solo", 20,["Jack", 9,["Fredo", 2, ["Kyle", 1], ["Luke", 1]],["Vincenzo", 1],["Fred", 6, ["Ela", 3], ["Han", 3]]],["John", 18, ["Rocco", 3], ["Nico", 14]]],2)
