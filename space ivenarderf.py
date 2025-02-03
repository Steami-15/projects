import pygame
import random

pygame.init()


#creates game screen and caption
screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("space invaderf")


clock = pygame.time.Clock()
GameOver = False


px = 400
py = 750
pxVel = 0
pyVel = 0
timer = 0

shoot = False

class Alien:
    def __init__(self, xpos,ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.Alive = True
        self.direction = 1
    def draw(self):
        pygame.draw.rect(screen, (250,250,250), (self.xpos, self.ypos, 40, 40))
    def move(self, time):
        if time % 300 == 0:
            self.ypos += 100
            self.direction *= -1
            return 0
        if time % 100 == 0:
            self.xpos += 50 * self.direction

        return time
    def collide(self, BulletX, BulletY):
        if self.Alive:
            if BulletX > self.xpos:
                if BulletX < self.xpos + 40:
                    if BulletY < self.ypos + 40:
                        if BulletY > self.ypos:
                            self.Alive = False
                            return False
        return True

    
class Bullet:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.Alive = False
    def move(self, xpos, ypos):
        if self.Alive == True:
            self.ypos -= 5
        if self.ypos < 0:
            self.Alive = False
            self.xpos = xpos
            self.ypos = ypos
    def draw(self):
        pygame.draw.rect(screen, (250,250,250), (self.xpos, self.ypos, 3, 20))



class Wall:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.numHit = 0 
    def draw(self):
        if self.numHit == 0:
            pygame.draw.rect(screen, (250, 250, 20), (self.xpos, self.ypos, 30, 30))
        if self.numHit == 1:
            pygame.draw.rect(screen, (150, 150, 10), (self.xpos, self.ypos, 30, 30))
        if self.numHit == 2:
            pygame.draw.rect(screen, (50, 50, 0), (self.xpos, self.ypos, 30, 30)) 
    def collide(self, BulletX, BulletY):
        if self.numHit > 3:
            if BulletX > self.xpos:
                if BulletX < self.xpos + 30:
                    if BulletY < self.ypos + 30:
                        if BulletY > self.ypos:
                            self.numHit += 1
                            return False
        return True

class Missle():
    def __init__(self):
        self.xpos = -10
        self.ypos = -10
        self.Alive = False
    def move(self):
        if self.Alive == True:
            self.ypos += 5
        if self.ypos > 800:
            self.Alive = False
            self.xpos = -10
            self.ypos = -10
    def draw(self):
        pygame.draw.circle(screen, (0,120,250), (self.xpos, self.ypos), 5)
        

bullet = Bullet(px+28, py)

missles = []
for i in range(10):
    missles.append(Missle())


armada = []
for i in range(4):
    for j in range(9):
        armada.append(Alien(j*70+50, i*60+50))

walls = []
for k in range(4):
    for i in range(2):
        for j in range(3):
            walls.append(Wall(j*30 + 200*k+ 50, i*30 + 600))

#BEGIN GAME LOOP######################################################
while not GameOver:
    gameEvents = pygame.event.get()
    # Input Section------------------------------------------------------------
    for event in gameEvents:  # quit game if x is pressed in top corner
        if event.type == pygame.QUIT:
            GameOver = True

    clock.tick(60)
    timer += 1
   

   
    keys = pygame.key.get_pressed()

    if keys[pygame.K_a]:
        pxVel = -5
    elif keys[pygame.K_d]:
        pxVel = 5
    else:
        pxVel = 0

    if keys[pygame.K_SPACE]:
        shoot = True
    else:
        shoot = False

    if shoot == True:
        bullet.Alive = True
    
    if bullet.Alive == True:
        bullet.move(px + 28, py)
        if bullet.Alive == True:
            for i in range(len(armada)):
                bullet.Alive = armada[i].collide(bullet.xpos, bullet.ypos)
                if bullet.Alive == False:
                    break

        if bullet.Alive == True:

            for i in range(len(walls)):
                bullet.Alive = walls[i].collide(bullet.xpos, bullet.ypos)
                if bullet.Alive == False:
                    break

    else:
        bullet.xpos = px + 28
        bullet.ypos = py


    for i in range(len(walls)):
        for j in range(len(missles)):
            if missles[j].Alive == True:
                if walls[i].collide(missles[j].xpos, missles[j].ypos) == False:
                    missles[j].Alive = False
                    print('collide')
                    break

    randoNumber =  random.randrange(100)
    if randoNumber > 2:
        randomNumber2 = random.randrange(len(armada))
        if armada[randomNumber2].Alive == True:
            for i in range(len(missles)):
                if missles[i].Alive == False:
                    missles[i].Alive = True
                    missles[i].xpos = armada[randomNumber2].xpos + 5
                    missles[i].ypos = armada[randomNumber2].ypos
                    break



    for i in range(len(missles)):
        missles[i].move()
  

    px += pxVel 

    
   
    #render section-----------------------------------vis

    screen.fill((0,0,0))

    bullet.draw()
    pygame.draw.rect(screen, (0,200,100), (px, 750, 60, 20))
    pygame.draw.rect(screen, (0,200,100), (px + 5, 745, 50, 20))
    pygame.draw.rect(screen, (0,200,100), (px + 20, 735, 20, 20))
    pygame.draw.rect(screen, (0,200,100), (px + 25, 730, 10, 20))

    for i in range (len(armada)):
        if armada[i].Alive == True:
            armada[i].draw()

    for i in range(len(armada)):
        timer = armada[i].move(timer)

    for i in range(len(walls)):
        walls[i].draw()

    for i in range(len(missles)):
        if missles[i].Alive == True:
            missles[i].draw()  




    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
