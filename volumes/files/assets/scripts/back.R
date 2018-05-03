# install.packages('ggplot2', repos="http://cran.us.r-project.org")
# install.packages('plotly', repos="https://cran.dcc.uchile.cl")

suppressMessages(library(ggplot2))
suppressMessages(library(plotly))

args <- commandArgs(trailingOnly = TRUE)
saida <- args[1]
dir <- args[2]

dados <- read.csv(saida, col.names = c("X", "Y"), header = F, sep=";")

p <- ggplotly(ggplot(data = dados, aes(x=X, y=Y)) + 
	geom_point() + ggtitle("Grafico Ponto Flutuante"))
htmlwidgets::saveWidget(as_widget(p), paste0(dir, "/plot.html"))