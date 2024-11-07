import pygame
pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption('side-scrolling game')
clock = pygame.time.Clock()

player = [100, 450, 0, 0] #xpos, ypos, xvel, yvel
platforms = [(500, 400), (600, 300), (800, 330), (950, 300), (1150, 250), (1300, 200), (1550, 250), (1700, 200), (1850, 300), (2050, 250)]
isOnGround = False
offset = 0

    

def draw_platforms():
    for i in range(len(platforms)):
        pygame.draw.rect(screen, (150, 10, 10), (platforms[i][0] + offset, platforms[i][1], 100, 30,))


def move_player():
    global isOnGround
    global offset
    isOnGround = False
    
    #ground collsion
    if (player[1] >= 450):
        isOnGround = True
        player[3] = 0
        player[1] = 450
    
        
    #platform collision
    for i in range(len(platforms)):
        if player[0]+50>platforms[i][0]+offset and player[0]<platforms[i][0]+100+offset and player[1]+50>platforms[i][1] and player[1]+50< platforms[i][1]+50:
            isOnGround = True
            player[1]=platforms[i][1]-50
            player[3] = 0
            print("on platform")
       
            
    #left/right keyboard movement
    if keys[pygame.K_LEFT]:
        if offset > 260 and player[0]>0:
            player[2] = -5
            
        elif player[0]>400 and offset < -1500:
            player[2] = -5
            
        elif player[0]>0:
            offset += 5
            
        else:    
            player[2]=0
            
    elif keys[pygame.K_RIGHT]:
        if offset > 260 and player[0]>0:
            player[2] = +5
            
        elif player[0]>400 and offset < -1500:
            player[2] = +5
            
        elif player[0]>0:
            offset -= 5
            player[2] = 0
        
        else:
            player [2]=0
    
    #jump mechanics
    if isOnGround == True and keys[pygame.K_UP]:
        player[3] = -15
        isOnGround = False
        
    #apply gravity
    if isOnGround == False:
        player[3] += 1 #gravity
        
    #update player position   
    player[0]+=player[2] #add velocity to position
    player[1]+=player[3]
#end of player move function-------------------------------------------------------
    
running = True




def draw_clouds():
    for x in range(0, 5000, 300):
        for i in range(3):
            pygame.draw.circle(screen, (255,255,255), (x + offset, 100), 40)
            pygame.draw.circle(screen, (255,255,255), (x - 50 + offset, 125), 40)
            pygame.draw.circle(screen, (255,255,255), (x + 50 + offset, 125), 40)
        pygame.draw.rect(screen, (255,255,255), (x - 50 + offset, 100, 100, 65))
        
def draw_tree():
    for x in range(0, 5000, 300):
        for i in range(3):
            pygame.draw.rect(screen, (110,38,14), (x - 50 + offset, 300, 25, 200))
            pygame.draw.circle(screen, (34, 130, 32), (x + offset, 300), 40)
            pygame.draw.circle(screen, (34, 130, 32), (x - 75 + offset, 300), 40)
            pygame.draw.circle(screen, (34, 130, 32), (x - 35 + offset, 250), 40)




while running: #main game loop
    clock.tick(60)
    print(player[0], player[1])
    #input section
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            
    
            
    keys = pygame.key.get_pressed()
    #physics section
    move_player()
    
    
        
        
    #render section
    screen.fill((135, 206, 235))
    pygame.draw.rect(screen, (34,139,34), (0, 500, 800, 200))
    draw_tree()
    draw_clouds()
    draw_platforms()
    pygame.draw.rect(screen, (255, 0, 255), (player[0], player[1], 50, 50))
    pygame.display.flip()
    
pygame.quit()
