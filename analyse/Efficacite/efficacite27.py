# 27efficacite.py
# Compile V
# Anonyme V
# Fonctionne V
# Passe les tests V
# Passe tous les tests V
# Passe mes tests V
# Noté sur 20

# Compléxité 5 selon Codacy (qui me parrait assez correct donc je vais mettre la note de 17.5/20)
# Les algos non récursifs sont d'une compléxité de O(n) et les récursifs sont de O(n*k) avec n la taille de la chaine et k le nombre d'itérations
# Cependant je pense que l'algo pourrait être un peu amélioré donc je vais retirer 0.5 points
# Note : 17/20
# Classement : 1eme

def RLE(chaine :str ) -> str:
    nvlchaine = ""
    cpt = 1
    for i in range(len(chaine)):
        if i<len(chaine)-1 and chaine[i] == chaine[i+1] and cpt<9: 
            cpt=cpt+1
        else :
            nvlchaine = nvlchaine + str(cpt) + chaine[i]
            cpt = 1
    return nvlchaine



def RLEit(chaine :str, iteration:int) -> str:
    if iteration != 1 :
        nvlchaine = RLE(chaine)
        return RLEit(nvlchaine,iteration-1)  #Pour la récursivité on enleve 1 jusqua que ce soit égale à 1
    return RLE(chaine)
    


def unRLE(chaine : str)->str:
    nvlchaine = ""
    for i in range(0,len(chaine),2):
        nvlchaine = nvlchaine + int(chaine[i])*chaine[i+1]    
    return nvlchaine


def unRLEit(chaine :str, iteration:int) -> str:
    if iteration != 1 :
        nvlchaine = unRLE(chaine)
        return unRLEit(nvlchaine,iteration-1) #Pour la récursivité on enleve 1 jusqua que ce soit égale à 1
    return unRLE(chaine)

