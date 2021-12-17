def main():
    from os import listdir
    from os.path import isfile, join
    onlyfiles = [f for f in listdir(".") if isfile(join(".", f))]
    classes = set()
    for i in onlyfiles:
        bb = i.split('_')[0]
        if bb.startswith('B0'):
            classes.add(bb)
    for i in classes:
        with open(i + 'good.dat', 'w') as good, open(i + 'bad.dat', 'w') as bad:
            for file in onlyfiles:
                from PIL import Image
                if file.startswith(i) and file.endswith('.png'):
                    img = Image.open(file)
                    width, heigth = img.size
                    good.write(f'{file} 1 0 0 {width} {heigth}\n')
                else:
                    bad.write(f"{file}\n")
            good.close()
            bad.close()
    
if __name__ == '__main__':
    main()
