# KPT è uno script python che viene eseguito al build del progetto, non fa parte del SO
# KPT sta per Kernel Partition Table e coincide coi 512bytes situati nel secondo settore che contengono da quale settore parte il kernel di "Project Omega" e per quanti dura nell'hdd
# Il KPT viene letto e interpretato dal codice situato nel primo settore, non è linguaggio macchina
# Oltre a questo KPT contiene anche il punto di inizio e il punto di fine della root (questi bytes verranno richiamati dal kernel quando andrà a cercare gli eseguibili principali)

import os, math

# Prendi la dimensione in kBytes del file "./out/kernel.bin"
kernelPath = "./out/kernel.bin"

def GetKernelKB(path):
    return os.path.getsize(path)

size = GetKernelKB(kernelPath)
nBlock = (int)(round(size / 512, 0))

print("Kernel size: ", size, "bytes")
print("Kernel size in sectors: ", nBlock)

# Ora ho bisogno di una regola per indicizzare il numero di blocchi dentro il KPT in modo che sia univoco e ridondante nel caso in cui il peso del kernel diventi importante
# In un blocco ci sono 512bytes, noi di un kernel dobbiamo salvare solo quanti blocchi dura visto che ci diamo la regola che inia tutto dal terzo blocco
# Stessa cosa succederà per la posizione della root visto che ogni blocco contiene l'indice a quello successivo...

# Quindi... mi calcolo quanti saranno i bit necessari per indicizzare nBlock blocchi (log in base 2 di nBlock), questo numero verrà diviso per 8 e avremo il numero di bytes necessari

nBitForHDD = (int)(math.log(nBlock, 2))
i = 1 # Per il ciclo while

if isinstance(nBitForHDD / 8, float):
    # Vuol dire che non riesco ad occupare un byte intero, colcoliamo quanto mi resta
    nBitForHDD = (int)(nBitForHDD)
    while True:
        if (nBitForHDD + i) % 8 == 0:
            nBitForHDD += i
            break
        i += 1

print("The kernel will be indexed with: ", (int(nBitForHDD / 8)), " bytes")

f = open("./bootloader/include/kpt.asm", "w+") # Crea il file tabella dentro bootloader
toWrite = "KPT_ENTRY: equ " + (str)(nBlock) + "\r\n"

f.write(toWrite)

f.close()

print("OK")