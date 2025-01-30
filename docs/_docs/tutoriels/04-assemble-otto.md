---
layout: documentation
hide_hero: false
hero_image: OttoIkea.png
hero_darken: true
image: OttoIkea.png
component_toc: true
doc_header: true
type: tuto

title: 04 - Assemblez votre Otto-MKS
subtitle: Etapes d'assemblage d'Otto-MKS
description: Suivez ces étapes pour assembler Otto-MKS !

author : Rémi Lacombe

time: 1
difficulty: 1

---
Vos pièces maintenant imprimées, suivez ce guide pour les assembler en un Otto-MKS fonctionnel !

{% include message.html title="Attention" message="**Prenez votre temps** à chaque étape, en vérifiant votre assemblage régulièment, notamment sur le **type de vis** à utiliser." status="is-warning" dismissable="true" icon="fas fa-exclamation-triangle" %}

{% include step-tuto.html 
greyBackground = false
image = "BOM.png"
title="Matériel"


content="Pour débuter, rassemblez votre matériel :
" %}

{% include step-tuto.html 
greyBackground = false
image = "step 1.png"
title="Etape 1 - Assembler le corps"


content="Insérez les servos dans la pièce **Body** aux emplacements reservés." %}

{% include step-tuto.html 
greyBackground = false
image = "step 2.png"
title="Etape 2 - Visser les servos"

content="**⚠️ Attention au type de vis**" %}

{% include step-tuto.html 
greyBackground = false
image = "step 3.png"
title="Etape 3 - Assembler les palonniers"

content="**Découpez** deux palonniers comme indiqué, et insérez les dans les pièces **Leg**.  
Poussez les palonniers pour atteindre le **fond des emplacements prévus.**" %}

{% include message.html title="Attention" message="Pour la prochaine étape, vous aurais besoin du code réalisé plus tôt, dans [**le tutoriel sur les servos**](/docs/tutoriels/09-servomotor/), permettant de les positionner à **90°**" status="is-warning" dismissable="true" icon="fas fa-exclamation-triangle" %}

{% include step-tuto.html 
greyBackground = false
image = "step 4.png"
title="Etape 4 - Assembler les jambes"

content="Branchez les deux servos sur la **carte électronique**, et éxecutez votre code de **remise à 90° des servos**.  
Insérez ensuite les **jambes** sur l'**axe des servomoteurs**, dans la **position indiquée**.
Débranchez les servos, et vérifiez que les **butées** des servomoteurs se trouvent bien à **90° de part et d'autre de la position neutre**.
" %}


{% include step-tuto.html 
greyBackground = false
image = "step 5.png"
title="Etape 5 - Visser les jambes"

content="Vissez les jambes dans les axes des servos.  
**⚠️ Attention au type de vis**
" %}

{% include step-tuto.html 
greyBackground = false
image = "step 6.png"
title="Etape 6 - Assembler palonniers des pieds"

content="Insérez les palonniers dans les pièces **Foot** jusqu'à la butée.
" %}

{% include step-tuto.html 
greyBackground = false
image = "step 7.png"
title="Etape 7 - Visser les palonniers des pieds"

content="Vissez les palonniers.  
**⚠️ Attention au type de vis**
" %}

{% include message.html title="Attention" message="Pour la prochaine étape, vous aurais besoin du code réalisé plus tôt, dans [**le tutoriel sur les servos**](/docs/tutoriels/09-servomotor/), permettant de les positionner à **90°**" status="is-warning" dismissable="true" icon="fas fa-exclamation-triangle" %}

{% include step-tuto.html 
greyBackground = false
image = "step 8A.png"
image_2 = "step 8B.png"
title="Etape 8 - Assembler les servos des pieds"

content="Branchez les deux servos sur la **carte électronique**, et éxecutez votre code de **remise à 90° des servos**.  
Insérez ensuite les **servomoteurs** dans les pièces **Foot** dans la **position indiquée**.
Débranchez les servos, et vérifiez que les **butées** des servomoteurs se trouvent bien à **90° de part et d'autre de la position neutre**.
" %}

{% include step-tuto.html 
greyBackground = false
image = "step 9.png"
title="Etape 9 - Visser les servos des pieds"

content="Vissez l'axe des servos.  
**⚠️ Attention au type de vis**.
" %}

{% include step-tuto.html 
greyBackground = false
image = "step 10A.png"
image_2 = "step 10B.png"
image_3 = "step 10C.png"
title="Etape 10 - Assembler les pieds"

content="Insérez les pieds dans les emplacements prévus dans les pièces **Leg**.  
Veillez à faire passer les fils par les trous de la pièce **Body**.
" %}

{% include step-tuto.html 
greyBackground = false
image = "step 13.png"
title="Etape 11 - Visser les pieds"

content="Vissez l'axe des servos.  
**⚠️ Attention au type de vis**.
" %}
---

{%
  include card_collections.html
  title="Pour aller plus loin"
  description="Trouvez d'autres tutoriels en lien avec le projet"
  type="tuto"
%}