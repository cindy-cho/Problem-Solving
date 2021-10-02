import requests
import random
import json

class truck:
    def __init__(self):
        self.p = 0
        self.load =0

    def __str__(self):
        return str(self.p) + ' ' + str(self.load)
    def __repr__(self):
        return '(' + str(self.p) + ' ' + str(self.load) + ')'

# API
def getlocation(url, headers, bycycle):
    path = 'locations'
    req = requests.get('/'.join([url,path]),headers=headers)

    j = req.json()

    for id, cnt in [(i['id'], i['located_bikes_count']) for i in j['locations']]:
        bycycle[id]=cnt
    
    return bycycle

def gettrucks(url,headers,trucks):
    path = 'trucks'
    req = requests.get('/'.join([url,path]), headers=headers)

    j = req.json()
    for id, p, cnt in [(i['id'], i['location_id'], i['loaded_bikes_count'])for i in j['trucks']] :
        trucks[id].p = p
        trucks[id].load = cnt

    return trucks

#simulate API
def simulate(url, header, data):
    path = 'simulate'
    req = requests.put('/'.join([url,path]), headers = header, data = data)

    return req.json()

def kakaotaxi(qid = 1):
    #for rest api
    url = '서버주소'
    path = 'start'
    token =''
    param = {'problem':qid}
    headers = {'X-Auth-Token':token, 'Content-Type': 'application/json'}

    msize = 0
    mean = 15

    if qid == 1:
        msize = 5
        mean = 2
    else:
        msize = 60
        mean = 3

    mymap = [[msize-i-1 + msize*j for j in range(msize)] for i in range(msize)]

    pos = { mymap[i][j] : (i,j) for i in range(msize) for j in range(msize)}

    bycycles = [0 for i in range(msize*msize)]

    tnum = [0,5,10]

    trucks = [truck() for i in range(tnum[qid])]
    req = requests.post('/'.join([url,path]),headers = headers, data=json.dumps(param))
    j = req.json()
    auth_key = j['auth_key']
    headers = {'Authorization': auth_key, ' Content-Type': 'applications/json'}

    next_command = [[] for i in range(len(trucks))]
    bnum = [0,4,3]

    prev_bycycle = [bnum[qid] for i in range(msize*msize)]

    for  i in range(720):
        trucksdes = [int(random.uniform(0,msize*msize)) for i in range(len(trucks))]
        bycycles = getlocation(url, headers, bycycle=bycycles)
        mmin = 100000000
        mini = 0
        mmax = -1000000000
        maxi = 0

        for i, j in enumerate(prev_bycycle[i] - bycycles[i] for i in range(len(byctcles))]):
            if mmin > j:
                mmin, mini=j,i
            if mmax <j:
                mmax, maxi = j,i
        
        trucks = gettrucks(url,headers,trucks)

        emergen = [i[0] for i in enumerate(bycycles) if i[1] ==0]

        i=0

        idx, next_command[i] = getdist(pos, t.p, trucksdes[i])

        next_command = []
        nextcommand.append({'truck_id':i, 'command' :ncom})

        #simulate api
        j = simulate(url, header=headers, data=json.dumps({'commands':nextcommand}))
        print(j['time'])

        prev_bycycle - [i for i in bycycles]

    req = requests.get(url +'/score', headers = headers)
    print(req.json()['score'])

kakaotaxi(2) #2번 문제라는 뜻

