# This challenge requires performing a visual XOR between the RGB bytes of the two images
#  - not an XOR of all the data bytes of the files.

from PIL import Image

# on va xor les pixels des deux images
# on va afficher le résultat

lemur = Image.open("lemur.png")
key = Image.open("flag.png")

# traduit les images en RGB
lemur_rgb = lemur.convert("RGB")
key_rgb = key.convert("RGB")

# Créer une nouvelle image pour le résultat
result = Image.new("RGB", lemur_rgb.size)

# Obtenir les pixels des deux images
pixels_lemur = lemur_rgb.load()
pixels_key = key_rgb.load()
pixels_result = result.load()

# Appliquer XOR sur chaque pixel
for x in range(lemur_rgb.width):
    for y in range(lemur_rgb.height):
        r1, g1, b1 = pixels_lemur[x, y]  # Pixel de l'image lemur
        r2, g2, b2 = pixels_key[x, y]    # Pixel de l'image key

        # Appliquer XOR pour chaque canal
        r = r1 ^ r2
        g = g1 ^ g2
        b = b1 ^ b2

        # Stocker le résultat
        pixels_result[x, y] = (r, g, b)

# Afficher ou enregistrer le résultat
result.show()  # Affiche l'image résultante
result.save("result.png")  # Sauvegarde l'image résultante