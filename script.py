import matplotlib.pyplot as plot

content = [line.split(',') for line in open("saida.csv", "r").readlines()]

t = [float(line.pop()[:-1]) for line in content]
s = [float(line[0]) for line in content]
i = [float(line[1]) for line in content]
r = [float(line[2]) for line in content]

plot.plot(s, 'g')
plot.plot(i, 'r')
plot.plot(r, 'y')


plot.show()