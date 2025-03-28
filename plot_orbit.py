import matplotlib.pyplot as plt

# Spécifier le chemin du fichier data.txt
file_path = '/home/utilisateur/Documents/M1 /Entrainement /Binaire/data.txt'

# Listes pour stocker les positions des étoiles
time = []
star1_x = []
star1_y = []
star2_x = []
star2_y = []

# Lire les données du fichier
with open(file_path, 'r') as file:
    for line in file:
        data = line.split()
        # Extraire les données du fichier : temps, positions de star1 et star2
        t = float(data[0])
        x1, y1, z1 = float(data[1]), float(data[2]), float(data[3])
        x2, y2, z2 = float(data[4]), float(data[5]), float(data[6])
        
        # Ajouter les données dans les listes
        time.append(t)
        star1_x.append(x1)
        star1_y.append(y1)
        star2_x.append(x2)
        star2_y.append(y2)

# Tracer les positions des deux étoiles
plt.figure(figsize=(8, 8))

# Trajectoire de l'étoile 1 (tracer des points)
plt.scatter(star1_x, star1_y, label='Étoile 1', color='blue', marker='+')

# Trajectoire de l'étoile 2 (tracer des points)
plt.scatter(star2_x, star2_y, label='Étoile 2', color='red', marker='+')

# Ajouter des étiquettes et un titre
plt.xlabel('Position X (en AU)')
plt.ylabel('Position Y (en AU)')
plt.title('Positions des Étoiles du Système Binaire')

# Ajouter une légende
plt.legend()

# Afficher le graphique
plt.grid(True)
plt.axis('equal')  # Assure que les axes ont la même échelle
plt.show()
