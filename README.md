# Super Trumps Challenge - Countries - Card Registration
Welcome to the "Super Trumps - Countries" challenge! In the Super Trumps game, players compare the properties of cards to determine the strongest. The theme of this Super Trumps game is "Countries," where you will compare the properties of cities.

The MateCheck company has hired you to develop the initial part of the game, which consists of registering the cards.

The challenge is divided into three levels: Novice, Adventurer, and Master, with each level adding more complexity to the previous one. You must choose which challenge you want to undertake.

🚨 Attention:

The Novice level of the challenge focuses only on registering the cards, using the scanf function to read the data and printf to display it.

🎮 Novice Level
At the Novice level, you will start by creating the basic Super Trumps game system with the theme "Countries." The cards will be divided by states, each with four cities.

Each country will be divided into eight states, identified by the letters A through H. Each state will have four cities, numbered 1 through 4. The combination of the state letter and the city number defines the map code (e.g., A01, A02, B01, B02).

🚩 Objective:
To create maps representing cities, containing the following properties:
Population
Area
GDP
Number of tourist attractions
⚙️ System Functionalities:
The system will allow the user to register city maps by manually entering the data via the command terminal.

After registration, the system will display the data for each city in a clear and organized manner.

📥 Data Input and 📤 Output:
The user enters the data for each map interactively.

After registration, the data is displayed with all the city's properties, one per line.

🛡️ Adventurer Level
At the Adventurer level, you will expand the system to include calculated properties, allowing for a more detailed analysis of the maps.

🆕 Difference from the Novice Level:
New Calculated Properties:
Population Density: Population divided by the city area.
GDP per Capita: Total GDP divided by the population.

⚙️ System Features:
The system will now automatically calculate Population Density and GDP per Capita based on the data entered.
These new properties will be added to the information displayed for each city.

📥 Data Input and 📤 Output:
The user continues to enter the data for each map interactively.

The system will display the data, including the new calculated properties, in a clear and organized manner.

🏆 Master Level
At the Master level, you will implement comparisons between maps, using relational operators and manipulating large numbers with precision.

🆕 Difference from Adventurer Level:
Card Comparison:
The system will allow the user to compare two cards based on the properties entered and calculated.
Each card will have a "Super Power," which is the sum of all properties.

⚙️ System Features:
The system will use relational operators to determine the winning card based on the compared properties.

The comparison will consider:
Population Density: The card with the lowest value wins.
Other Properties: The card with the highest value wins.
The results of the comparisons will be clearly displayed for each property.

📥 Data Input and 📤 Data Output:
The user enters the cards to be compared.
The system displays the results of the comparisons, indicating the winning card for each property.
