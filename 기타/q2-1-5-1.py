#[q2-1-5-1.py]
#각 노드 연결 정보
searchNode = { 1:[2,5], 2:[1,3,4], 3:[2], 4:[2], 5:[1,6,7], 6:[5], 7:[5]}

#해당 프로그램이 하는 일
#주어진 트리를 stack을 이용하여 깊이우선 탐색한다. (DFS)

#노드의 방문순서를 저장하는 visited 딕셔너리 생성
visited={}
#빈 스택 생성
stack = list()

#스택에 출발노드인 1 을 집어넣음
stack.append(1)

#스택에 값이 있는 동안 계속 수행한다.
while stack:
    # 현재 노드에 스택의 제일 위에 들어있는 값을 넣어준다.
    node = stack.pop()
    # 현재 노드에 방문한적이 없으면 if문을 수행한다.
    if node not in visited:
        #visted에서 해당 key의 value값을 True로 바꿔주어 현재 노드를 방문했다고 값을 갱신한다.
        visited[node]=True
        #stack에  현재 노드와 연결된 노드를 뒤집어서 넣어준다. (stack은 LIFO이기 때문)
        stack.extend(reversed(searchNode[node]))


#visited에 저장된 key값을 순서대로 출력한다. - 노드의 방문 순서대로 출력된다.
print(list(visited.keys()))


#[q2-1-5-2.py]
#해당 프로그램이 하는 일
#주어진 트리를 queue를 이용하여 너비 우선 탐색한다. (BFS)

#노드의 방문순서를 저장하는 visited 딕셔너리 생성
visited = {}
#빈 큐 생성
queue = list()

#큐에 출발노드인 1 을 집어넣음
queue.append(1)

#큐에 값이 있는 동안 계속 수행한다.
while queue:
    # 현재 노드에 큐의 제일 처음에 들어있는 값을 넣어준다.
    node = queue.pop(0)
    # 현재 노드에 방문한적이 없으면 if문을 수행한다.
    if node not in visited:
        #visted에서 해당 key의 value값을 True로 바꿔주어 현재 노드를 방문했다고 값을 갱신한다.
        visited[node] = True
        #큐에  현재 노드와 연결된 노드를 값을 넣어준다. (queue는 FIFO이기 때문)
        queue.extend(searchNode[node])

#visited에 저장된 key값을 순서대로 출력한다. - 노드의 방문 순서대로 출력된다.
print(list(visited.keys()))
