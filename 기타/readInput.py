inputFile = open('{파일패스}','r')
outputFile = open('output.txt','w')
lines = inputFile.readlines()
index = 1
for line in lines:
    outputFile.write("%d: %s" %(index, line))
    index+=1


inputFile.close()
outputFile.close()
