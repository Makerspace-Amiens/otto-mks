---
layout: documentation
hide_hero: false
hero_image: bounding_box.png
hero_darken: true
image: bounding_box.png
component_toc: true
doc_header: true
type: homologation

title: 📏 Homologation
subtitle: Ensemble des règles à respecter pour participer aux épreuves !
description: Ensemble des règles à respecter pour participer aux épreuves ! 

todo: 10

author: Adrien BRACQ & Rémi LACOMBE
---

{% include step-tuto.html 
greyBackground = true
title = "Dimensions"
content="Premièrement, votre robot devra tenir dans un volume de :

**Largeur : 150mm**  
**Longueur : 150mm**  
**Hauteur : 200mm**  

Pour valider cette règle, votre robot devra rentrer dans une boîte aux bonnes dimensions
" 
image="bounding_box.png" %}

{% include step-tuto.html 
greyBackground = true
title = "Mode de contrôle"
content="En fonction de l'épreuve, deux mode de fonctionnement pourront vous être demandés, précisé dans le réglement de l'épreuve :

**- Mode autonome**  
Votre robot doit être en mesure de réaliser l'épreuve sans aide extérieur, il devra donc être programmé en avance pour jouer.
Le mode de démarrage est propre à chaque épreuve et est spécifié dans leurs réglements

**- Mode télécommandé**
Vous devrez programmer une solution de contrôle à distance, par exemple grâce à l'application [RemoteXY](https://makerspace-amiens.fr/otto-mks/docs/tutoriels/10-remoteXY/)
" 
image="command_mode.png" %}

{% include step-tuto.html 
greyBackground = true
title = "Déplacement"
content="Même si l'ajout de nouveaux actionneurs est autorisé, votre robot devra impérativement se déplacer en **marchant**." 
image="must_walk.png" %}

{% include step-tuto.html 
greyBackground = true
title = "Esthétique"
content="Votre robot modifié doit conservé **l'esprit** et **l'ésthetique** du projet Otto" 
image="keep_aspect.png" %}