#version 330 core

in vec2 tex_coords;

uniform sampler2D texture_id;

void main()
{
    gl_FragColor = texture(texture_id, tex_coords);
}