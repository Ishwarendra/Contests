heros=['spider man','thor','hulk','iron man','captain america']
heros.append("black panther")
heros.remove('black panther')
# 'remove hulk and thor and add doc strange in their place'
heros[1:3] = ['doctor strange']
print(heros)