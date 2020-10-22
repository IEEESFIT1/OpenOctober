def resistancebands(bc1, bc2, bc3, bc4):     #define 4 band resistor colors
    bandcolors = {'black': '0',
                   'brown': '1',
                   'red': '2',
                   'orange': '3',
                   'yellow': '4',
                   'green' : '5',
                   'blue' : '6',
                   'violet' : '7',
                   'grey' : '8',
                   'white': '9'}  	        #create a set of data of colorbands and their respective values

    multiplier = {'black': '1',
                  'brown': '10',
                  'red': '100',
                  'orange': '1k',
                  'yellow': '10k',
                  'green' : '100k',
                  'blue' : '1M',
                  'violet' : '10M',
                  'grey' : '100M',
                  'white': '1G'}   	        #create a set of data of colorbands and their multiplicative values

    tolerance = {'brown': '+/- 1 %',
                  'red' : '+/- 2 %',
                 'green': "+/- 0.5 %",
                  'blue': '+/- 0.25 %',
                 'violet' : '+/- 0.1 %',
                  'gold': '+/- 5 %',
                 'silver' : '+/- 10 %',
                  'none': '+/- 20 %'}       #create a set of data of colorbands and their tolerance values

    if bc1 in bandcolors and bc2 in bandcolors and bc3 in multiplier and bc4 in tolerance:
        band1 = bandcolors.get(bc1)
        band2 = bandcolors.get(bc2)
        band3 = multiplier.get(bc3)
        band4 = tolerance.get(bc4)
        print("Resistance = " + band1 + band2 + "*" + band3 + " ohms " + band4)
    else:
        print("Invalid color input")

bc1 = input("Color1")
bc2 = input("Color2")
bc3 = input("Color3")
bc4 = input("Color4")
resistancebands(bc1, bc2, bc3, bc4)
