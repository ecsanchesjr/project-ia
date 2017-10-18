#!/usr/bin/Rscript
args = commandArgs(trailingOnly=TRUE)


fileName <- paste("../logs/Graphs/", args[25], ".pdf", sep="")
pdf(fileName, height=10, width=10)


for (i in 1:12){
  dados <- read.csv(file=args[i], header=TRUE, sep=",")
  if(i==1){
    max = dados
    minY = min(dados[,3])
    maxY = max(dados[,3])
  }
  if(length(max[,1]) < length(dados[,1])){
    max = dados
  }
  if(min(dados[,3]) < minY){
    minY = min(dados[,3])
  }
  if(max(dados[,3]) < minY){
    maxY = min(dados[,3])
  }
}
data <- data.frame(max[,1], max[,3])
plot(data, type="l", col=1, xlab="Generations", ylab="Distance of Best Tour", lwd="1", main=args[26], ylim=c(minY, maxY))

library(RColorBrewer)  # só 9 colors
cols <- brewer.pal(n=12,name="Set1")

for(i in 1:12){
  dados <- read.csv(file=args[i], header=TRUE, sep=",")
  data <- data.frame(dados[,1], dados[,3])
  lines(data, type="l", col=cols[i-1], lwd="1.5")
}

grid(NULL, NULL, lty=10)

legend("topright", legend=c(args[13],args[14],args[15],args[16],args[17],args[18],args[19],args[20],args[21],args[22],args[23],args[24]), col=c(1,2,3,4,5,6,7,8,9,10,11,12), lty=1, cex=2, lwd=3, title="Elitism % - Mutation %", bg="white")
dev.off()