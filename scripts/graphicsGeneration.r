#!/usr/bin/Rscript
args = commandArgs(trailingOnly=TRUE)
library(xtable)

colors <- c("darkolivegreen", "blue", "blueviolet", "brown1", "darkgoldenrod", "chocolate", "darkgreen", "deeppink", "green", "olivedrab", "orangered", "black", "black")

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

if(args[27] == "berlin52"){
  opt=7542
}else{
  opt=14379

}

data <- data.frame(max[,1], max[,3])
minY=(opt-1000)
plot(data, type="l", col="white", xlab="Generations", ylab="Distance of Best Tour", lwd="1", main=args[26], ylim=c(minY, maxY))

tab <- data.frame(MaxValues=max(dados[,3]), MinValues=min(dados[,3]))

for(i in 1:12){
  dados <- read.csv(file=args[i], header=TRUE, sep=",")
  data <- data.frame(dados[,1], dados[,3])
  lines(data, type="l", col=colors[i-1], lwd="1.5")

  tabAux <- data.frame(MaxValues=max(dados[,3]), MinValues=min(dados[,3]))
  tab <- rbind(tab, tabAux)
}

abline(h=opt, col="Black", lwd=2, lty=10)

write(fileName, "/home/elss/Documentos/Git Repos/project-ia/logs/tables.txt", sep="\t", append=TRUE)
write.table(print(xtable(tab),hline.after=c(2,3)) , "/home/elss/Documentos/Git Repos/project-ia/logs/tables.txt", sep="\t", append=TRUE)

grid(NULL, NULL, lty=10)

legend("topright", legend=c(args[13],args[14],args[15],args[16],args[17],args[18],args[19],args[20],args[21],args[22],args[23],args[24]), col=c(colors[0], colors[1], colors[2], colors[3], colors[4], colors[5], colors[6], colors[7], colors[8], colors[9], colors[10], colors[11]), lty=1, cex=0.8, lwd=3, title="Elitism % - Mutation %", bg="white")
dev.off()