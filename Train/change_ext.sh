for f in *.png; do 
    mv -- "$f" "${f%.txt}.jpg"
done
