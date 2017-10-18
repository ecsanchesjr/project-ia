dados <- read.csv(file="/home/elss/Documentos/Git Repos/project-ia/logs/berlin52/test-10-0-0-10-2/run_1.stats.csv", header=TRUE, sep=",")
dados1 <- read.csv(file="/home/elss/Documentos/Git Repos/project-ia/logs/berlin52/test-10-0-0-10-2/run_2.stats.csv", header=TRUE, sep=",")

data <- data.frame(dados[1][,1], dados[1][,3])
plot(data, type="l", col=2, xlab="Gerações", ylab="Distância do melhor indivíduo", main="BATATA", lwd="1")
data1 <- data.frame(dados1[,1], dados1[,3])
lines(data1, type="l", col=3, lwd="0.5")
grid(NULL, NULL, lty=5)
legend("topright", legend=c("1", "2"), col=c(1,2), lty=1.2, cex=0.8)

#############################################


for (i in 1:10){
  fileT <- paste("/home/elss/Documentos/Git Repos/project-ia/logs/berlin52/test-10-0-0-10-2/run_",i,".stats.csv", sep="")
  dados <- read.csv(file=fileT, header=TRUE, sep=",")
  if(i==1){
    max = dados
  }
  if(length(max[,1]) < length(dados[,1])){
    max = dados
  }
}

#dados <- read.csv(file="/home/elss/Documentos/Git Repos/project-ia/logs/berlin52/test-10-0-0-10-2/run_1.stats.csv", header=TRUE, sep=",")
data <- data.frame(max[,1], max[,3])
plot(data, type="l", col=1, xlab="Gerações", ylab="Distância do melhor indivíduo", main="BATATA", lwd="1")
cat ("uahuahauhaa")

for(i in 1:10){
  fileT <- paste("/home/elss/Documentos/Git Repos/project-ia/logs/berlin52/test-10-0-0-10-2/run_",i,".stats.csv", sep="")
  dados <- read.csv(file=fileT, header=TRUE, sep=",")
  data <- data.frame(dados[,1], dados[,3])
  cat("\n")
  cat("==========================================================")
  cat("\n")
  cat(dados[,3])
  lines(data, type="l", col=i, lwd="1")
}
legend("topright", legend=c("10 Mut 10 Elit", "2"), col=c(1,2), lty=1.2, cex=2.8)
