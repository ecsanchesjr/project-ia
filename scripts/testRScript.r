#!/usr/bin/Rscript

dados <- read.csv(file="/home/elss/Documentos/Git Repos/project-ia/logs/berlin52/test-10-0-0-10-2/run_1.stats.csv", header=TRUE, sep=",")
dados1 <- read.csv(file="/home/elss/Documentos/Git Repos/project-ia/logs/berlin52/test-10-0-0-10-2/run_2.stats.csv", header=TRUE, sep=",")

pdf("Graphs/test.pdf", height=10, width=10)

data <- data.frame(dados[,1], dados[,3])

plot(data, type="l", col=2, xlab="Gerações", ylab="Distância do melhor indivíduo", main="BATATA", lwd="1")

data1 <- data.frame(dados1[,1], dados1[,3])

lines(data1, type="l", col=3, lwd="0.5")

grid(NULL, NULL, lty=5)
legend("topright", legend=c("1", "2"), col=c(1,2), lty=1.2, cex=0.8)
dev.off()