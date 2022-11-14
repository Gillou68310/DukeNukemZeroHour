import ida_struct

class STRUCT:
    def __init__(self, i):
        id = ida_struct.get_struc_by_idx(i)
        self.stru = ida_struct.get_struc(id)
        self.name = ida_struct.get_struc_name(id)
        self.size = ida_struct.get_struc_size(id)

structs = []
count = ida_struct.get_struc_qty()
for i in range(count):
    structs.append(STRUCT(i))

for i in range(0, len(structs)):
    for j in range(i+1, len(structs)):
        if structs[i].size == structs[j].size:
            if 'unk' in structs[i].name or 'Unk' in structs[i].name \
                or 'unk' in structs[j].name or 'Unk' in structs[j].name:
                # Checking size of first struct member
                #member = structs[i].stru.get_member(0)
                #size1 = ida_struct.get_member_size(member)
                #member = structs[j].stru.get_member(0)
                #size2 = ida_struct.get_member_size(member)
                print('Possible math between ' + structs[i].name + ' and ' + structs[j].name)