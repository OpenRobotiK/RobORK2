﻿/** \addtogroup robORK
 * @{
 *
 *\mainpage Projet Open RobotiK
 *\section intro Introduction
 * Nous sommes une assosiation de loi 1901 don le statut est : \n
 * La mutualisation et la diffusion de savoirs, autour de la robotique, grâce à des procédés open-sources 
 * et open-hardware. La diffusion se fera via un site internet, et par la participation à des événements 
 * publiques tel que la Coupe de France de Robotique ou Eurobot. \n
 *
 * Notre principal objectif est donc très simple: Participer à la coupe de France de robotique. Nous sommes une
 * nouvelle équipe, en conséquence de quoi notre objectif de performance est modeste.
 *
 * \section membreinfo Information sur les membres
 * \subpage Mael \n
 * \subpage Florent \n
 * 
 * 
 *
 * 
 * \section deviceinfo Information sur le matériel
 * * <a href="../datasheet/encoder-specification-ig32e-35k.pdf" TARGET="_blank">\link Encodeur </a> \n
 * * <a href="../datasheet/pont_en_h.pdf" TARGET="_blank">\link Pont en H </a> \n
 * * <a href="../datasheet/technical-drawing-data-ig32e-35k.pdf" TARGET="_blank">\link Moteur </a> \n
 * * <a href="../datasheet/DS_MM232R.pdf" TARGET="_blank">\link Convertiseur UART </a> \n
 * * <a href="../datasheet/lpcxpresso.lpc1769.schematic.pdf" TARGET="_blank">\link Schéma carte LPCXpresso </a> \n
 * * <a href="../datasheet/UM10360.pdf" TARGET="_blank">\link Datasheet Microcontrôleur </a> \n 
 *
 * \section codeinfo Information sur le code
 * Git : <a href=" https://github.com/OpenRobotiK/RobORK2 ">\link Code source </a>  \n
 * * \ref ADC \n
 * * \ref EEPROM \n
 * * \ref main \n
 * * \ref PWM \n
 * * \ref UART \n
 * * \ref watchdog \n
 *  
 * \section electronique Electronique
 * 
 * <a href="../electronique/pont en H v2.1 miroir.pdf" TARGET="_blank">\link Carte pont en H </a> \n 
 * \n
 * \section mecanique Mécanique 
 * Pour la partie mécanique nous avons utilisé une RepRap. \n
 * \n
 * <a href="../mecanique/Fixation_Moteur.STL" TARGET="_blank">\link Fixation moteur </a> \n
 * \n
 * 
 * 
 * \section comment_faire Comment faire ? 
 * \ref Grave_une_carte \n
 * 
 *
 *
 *
 * \n\n\n\n\n\n\n
 * Date: 20/10/2012 \n 
 *\section infodoc Information sur cette documentation
 * Cette documentation a été générée avec \ref Doxywizard \n
 * @}
 */


 
 /** 
 *\addtogroup robORK
 * @{
 *\defgroup Mael Mael Gaudy
 * @{
 *\page Mael Mael Gaudy
 * Jeune ingénieur de 23, je suis diplomé de l'ENSSAT depuis septembre 2012.\n
 * Je suis actuellement consultant pour la société ALTEN, en poste dans la PME aviwest. Mes travaux consiste en du développement d'IHM sous le framework Qt.\n
 * Si vous avez des questions ou si vous voulez plus de renseignements vous pouvez me contacter à cette adresse : <a href="mailto:mael.gaudy@gmail.com?subject=Renseignement Open Robotik">\link mael.gaudy@gmail.com </a>  \n
 *
 * 
 * \n\n
 *\section infodoc Information sur cette documentation
 * Cette documentation a été générée avec \ref Doxywizard \n
 *
 *
 * @}
 * @}
*/


 /** 
 *\addtogroup robORK 
 * @{
 *\defgroup Florent Florent Lyphout
 * @{
 *\page Florent Florent Lyphout
 * J'ai 24 ans, je viens d'un petit vilage à côté de Clermont-ferrand. \n
 * Je suis titulaire d'un diplôme d'ingénieur d'optronique de l'ENSSAT à Lannion.\n
 * Actuellement je travaille dans une PME de Lannion, IDIL Fibres Optiques, où je développe 
 * des cartes électroniques et du soft pour contrôler des lasers ou des photodiodes.\n\n 
 * Si vous avez des questions ou si vous voulez plus de renseignements vous pouvez me contacter à cette adresse : <a href="mailto:Lyphout.florent@gmail.com?subject=Renseignement Open Robotik">\link Lyphout.florent@gmail.com </a>  \n
 * 
 * 
 * \n\n
 *\section infodoc Information sur cette documentation
 * Cette documentation a été générée avec \ref Doxywizard \n
 *
 *
 * @}
 * @}
*/

/** 
 *\addtogroup robORK 
 * @{
 *\defgroup Grave_une_carte Comment graver une carte électronique
 * @{
 *\page Grave_une_carte Comment graver une carte électronique
 * 
 * \section materiel Matériel nécessaire : 
 * * de l'eau oxygénée \n 
 * * de l'acide chlorhydrique  \n
 * * une imprimante laser \n
 * * du papier glacé \n
 * * un fer à repasser \n
 * * un récipient en plastique \n
 * * des gants \n
 * * une plaque de pcb standard sans présensibilisation \n
 *  
 * 
 * \section transfert Le transfert 
 * Il faut imprimer un typon en miroir sur le papier glacé. Puis, il faut 
 * couper la plaque de PCB à la scie à metaux. Ensuite, il faut scotcher 
 * le papier sur la plaque de cuivre (le côté imprimé du côté du cuivre).
 * Puis, il faut passer le fer à repasser sur le côté papier pour que l'encre
 * soit transférée sur le cuivre durant 2 min. Ensuite, il faut retirer le 
 * papier avec de l'eau, pour qu'il ne reste plus de papier ou d'encre sur les pistes
 * et les pastilles. Si il reste du papier aux endroits où il ne devrait pas, il
 * est possible de grater le papier en trop à l'aide d'un cuteur.\n
 * <a href="../Image/pcb.jpg" TARGET="_blank" >\link image transféré </a> \n 
 * 
 * \section gravure La gravure
 * Pour graver nous avons fait le choix de ne pas utiliser de perchlorure de fer
 * car il n'est pas facile de se débarrasser du perchlorure de fer usé. Nous avons 
 * utilisé une methode à base d'acide chlorhydrique et d'eau oxygénée. 
 * Pour graver, il faut mettre 3 volumes d'eau, puis 2 volumes d'acide et enfin 1 volume d'eau oxygénée 
 * dans le récipient en plastique, puis plonger la plaque dans le mélange jusqu'à ce qu'il n'y ait
 * plus de cuivre visible. \n
 * <a href="../Image/plaque_grave.JPG" TARGET="_blank" >\link image pcb gravé </a> \n 
 * <a href="../Image/plaque_vernis.JPG" TARGET="_blank" >\link image vernis </a> \n 
 * 
 * \section percage Le perçage
 * \n
 * \section soudure La soudure
 * \n\n
 * \section infodoc Information sur cette documentation
 * Cette documentation a été générée avec \ref Doxywizard \n
 *
 *
 * @}
 * @}
*/
 
 
 /** 
 *\addtogroup robORK
 * @{
 *\defgroup Robot Notre robot
 * @{

 *\page Robot Notre robot
 * 
 * Répondant au doux nom de code RobORK notre robot se veut simple mais efficace. Il est réalisé, pour la plus grande partie,
 * à l'aide de l'imprimante 3D que nous nous sommes mis à disposition.
 *
 *\section Méca Conception Mécanique
 * Le règlement pour cette année 2013 demandant des dimensions non déployées "réduites" nous avons cherché à mettre au point un système
 * de motorisation peu encombrant. La solution la moins couteuse en temps et ressources qui nous est apparu était de désaxer les moteurs
 * l'un par rapport à l'autre. Bien que cette solution soit un peu déroutante elle fonctionne. Il convient tout de même d'émmetre quelques
 * réserves sur ce principe. Il faut éviter au maximums les grands arc de cercles pour se déplacer, ils provoquent des glissements non déterminés.
 * Notre robot n'a pas pour vocation de se déplacer à de grandes vitesses ce qui tant également à les diminuer.
 *
 *\section Stratégie Stratégie
 * Notre objectif de stratégie pour ce robot est simple. Dans un premier mouvement il va chercher à faire basculer tous ses cadeaux, il va ensuite
 * se diriger vers sa zone de départ en attrapant/poussant un maximum de verres. Son troisième mouvement sera d'aller souffler quelques bougies
 * à l'aide d'un bras télescopique au bout du quel sera accroché une bobine de flipper (pour venir percuter les balles de tenis).
 * 
 * \n\n
 *\section infodoc Information sur cette documentation
 * Cette documentation a été générée avec \ref Doxywizard \n
 *
 *
 * @}
 * @}
*/
