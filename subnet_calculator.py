if __name__ == '__main__':
  ip = list(map(int, input('Enter Octets of IP: ').split()))
  cidr = int(input('Enter CIDR: '))

  print(f'Final IP Address: {ip[0]}.{ip[1]}.{ip[2]}.{ip[3]}/{cidr}')

  if cidr % 8 == 0:
    if cidr == 8:
      print('Classful: C')
    elif cidr == 16:
      print('Classful: B')
    elif cidr == 24:
      print('Classful: A')
  else:
    subnets = 2 ** (cidr%8)
    print('Subnets:', subnets)
  
  print('Hosts per subnet:', 2 ** (32 - cidr))
  
  # Calculate subnet mask
  mask = [255] * (cidr//8)
  mask.append('0')
  for i in range(cidr%8):
    mask[-1] = int(mask[-1]) + (2 ** (8 - i - 1))
  mask += [0] * (4 - len(mask))
  print('Subnet mask:', '.'.join(map(str, mask)))
