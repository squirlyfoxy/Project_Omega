# KPT è uno script python che viene eseguito al build del progetto, non fa parte del SO
# KPT sta per (Kernel Partition Table), sono 512bytes (situati nel secondo settore) che contengono da quale settore parte il kernel di "Project Omega" e per quanti dura nell'hdd
# Il KPT viene letto e interpretato dal codice situato nel primo settore, non è linguaggio macchina
# Oltre a questo KPT contiene anche il punto di inizio e il punto di fine della root (questi bytes verranno richiamati dal kernel quando andrà a cercare gli eseguibili principali)