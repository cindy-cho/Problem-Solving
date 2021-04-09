//DBSCAN 알고리즘
Input : X : dataset
        e : neighbor distance
        threshold : minimun number of data to form cluster nC
Output : y : labes

//Algorithm 1 : DBSCAN
DBSCAN(dataset X, distance e, minimun number of data threshold){
    labes y
    k = 0 <- number of clusters
    for x in X:
        y(x) = not visited

    for x in X:
        if(y(x) is not visited):
            X(x) = SCAN(x,e) <- neighbors of y(x)
            if(abs(X(x)) >= nc): 
                K +=1
                y(x) = 
                for z in X(x):
                    if(y(z) is not visited):
                        y(z) = k <- mark visited
                        X(z) = SCAN(x,e) <- neighbors of y(z)
                        if( abs(X(z)) >= nc):
                            X(x) = X(x)U X(z)
            else:
                y(x) = NOISE

    return y
}

//Algorithm 2 : SCAN
SCAN(data point x, distance e){
    neighbors X
    for z in X:
        if(d(x,z) <= e):
            X(x) = X(x) U z
    return X(x)
}

