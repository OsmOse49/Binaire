import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Spécifier le chemin du fichier data.txt
file_path = '/home/utilisateur/Documents/M1 /Entrainement /Binaire/data.txt'

# Listes pour stocker les positions des étoiles
time, star1_x, star1_y, star2_x, star2_y = [], [], [], [], []

# Lire les données du fichier
with open(file_path, 'r') as file:
    for line in file:
        data = line.split()
        t = float(data[0])
        x1, y1 = float(data[1]), float(data[2])
        x2, y2 = float(data[4]), float(data[5])
        
        time.append(t)
        star1_x.append(x1)
        star1_y.append(y1)
        star2_x.append(x2)
        star2_y.append(y2)

# Conversion en tableaux numpy
star1_x = np.array(star1_x)
star1_y = np.array(star1_y)
star2_x = np.array(star2_x)
star2_y = np.array(star2_y)

# Création de la figure
fig, ax = plt.subplots(figsize=(8, 8))
ax.set_xlabel("Position X (en AU)")
ax.set_ylabel("Position Y (en AU)")
ax.set_title("Animation du Mouvement des Étoiles")
ax.grid(True)

# Définition automatique des limites des axes
ax.set_xlim(min(star1_x.min(), star2_x.min()) - 1, max(star1_x.max(), star2_x.max()) + 1)
ax.set_ylim(min(star1_y.min(), star2_y.min()) - 1, max(star1_y.max(), star2_y.max()) + 1)

# Création des points animés avec scatter
star1_plot = ax.scatter([], [], color='blue',s=300, label='Étoile 1')
star2_plot = ax.scatter([], [], color='red',s=300, label='Étoile 2')
ax.legend()

# Fonction d'initialisation
def init():
    star1_plot.set_offsets(np.array([[np.nan, np.nan]]))
    star2_plot.set_offsets(np.array([[np.nan, np.nan]]))
    return star1_plot, star2_plot

# Fonction de mise à jour
def update(frame):
    star1_plot.set_offsets(np.array([[star1_x[frame], star1_y[frame]]]))
    star2_plot.set_offsets(np.array([[star2_x[frame], star2_y[frame]]]))
    return star1_plot, star2_plot

# Création de l'animation
ani = animation.FuncAnimation(fig, update, frames=len(time), init_func=init, blit=True, interval=10)

# Afficher l'animation
plt.show()

