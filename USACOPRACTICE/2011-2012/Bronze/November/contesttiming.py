from datetime import datetime
a=input().split()
days=a[0]
hours=a[1]
minutes=a[2]
minpassed=0
minpassed+=(int(days)-11)*1440
currenttime=str(hours)+":"+str(minutes)
pasttime="11:11"
FMT = '%H:%M'
tdelta = str(datetime.strptime(currenttime, FMT) - datetime.strptime(pasttime, FMT))

a=tdelta.split(':')
minpassed+=(int(a[0]))*60
minpassed+=(int(a[1]))
print(minpassed)