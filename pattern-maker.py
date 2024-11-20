import pygame
pygame.init()
screen = pygame.display.set_mode((1200, 800))
pygame.display.set_caption("Pattern Generator")

# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BROWN = (139, 69, 19)  
RED = (255, 0, 0)
GREEN = (0, 255, 0)
DARK_BLUE = (11, 41, 141)
YELLOW = (242, 253, 7)
pop = pygame.mixer.Sound("pop2.mp3")

# Starting settings
current_color = RED
current_shape = "triangle"
SHAPE_SIZE = 40
pygame.mixer.music.load("instrumental.mp3")
pygame.mixer.music.play(-1)
# List of shapes (each shape is: [x, y, size, color, type])
shapeList = [] #this is going to be a LIST of LISTS!

# Initialize font for instructions
font = pygame.font.Font(None, 36)

# Main game loop-------------------------------------------------------------------------------------
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            

        # Check for key presses
        elif event.type == pygame.KEYDOWN:
            
            #numbers select what shape to draw
            if event.key == pygame.K_1:
                current_shape = "ellipse"  # Select ellipse
            elif event.key == pygame.K_2:
                current_shape = "hexagon"  # Select hexagon
            elif event.key == pygame.K_3:
                current_shape = "triangle"  # Select triangle
                
            #letters select what color to draw with
            if event.key == pygame.K_r:
                current_color = RED  # Change to red
            elif event.key == pygame.K_g:
                current_color = GREEN  # Change to green
            elif event.key == pygame.K_b:
                current_color = BROWN  # Change to brown
            elif event.key == pygame.K_w:
                current_color = WHITE
            elif event.key == pygame.K_p:
                current_color = DARK_BLUE
            elif event.key == pygame.K_y:
                current_color = YELLOW

        # Check for mouse click
        elif event.type == pygame.MOUSEBUTTONDOWN:
            mouse_x, mouse_y = pygame.mouse.get_pos()
            new_shape = [mouse_x, mouse_y, SHAPE_SIZE, current_color, current_shape]
            shapeList.append(new_shape)  # Add new shape to the list
            pygame.mixer.Sound.play(pop)
    # Clear the screen
    screen.fill(BROWN)

    # Draw all shapes directly in the loop
    for i in range(len(shapeList)):
        x = shapeList[i][0]
        y = shapeList[i][1]
        size = shapeList[i][2]
        color = shapeList[i][3]
        kind = shapeList[i][4]

        if kind == "ellipse":
            pygame.draw.ellipse(screen, color, (x - size, y - size // 2, size * 2, size))  # Ellipse dimensions
        elif kind == "hexagon":
            points = [
                (x, y - size),  # Top
                (x + size, y - size // 2),  # Top-right
                (x + size, y + size // 2),  # Bottom-right
                (x, y + size),  # Bottom
                (x - size, y + size // 2),  # Bottom-left
                (x - size, y - size // 2)   # Top-left
            ]
            pygame.draw.polygon(screen, color, points)
        elif kind == "triangle":
            points = [
                (x, y - size),           # Top point
                (x - size, y + size),    # Bottom-left point
                (x + size, y + size)     # Bottom-right point
            ]
            pygame.draw.polygon(screen, color, points)
        

    # Display instructions at the top
    instructions = font.render("1: Ellipse  2: Hexagon  3: Triangle", True, BLACK)
    instructions2 = font.render ("R: Red  G: Green  B: Brown W: White P: Dark Blue Y: Yellow", True, BLACK)
    screen.blit(instructions, (10, 0))
    screen.blit(instructions2, (10, 50))

    # Update the screen
    pygame.display.flip()

pygame.quit()
