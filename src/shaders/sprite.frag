precision mediump float;

varying vec2 v_fragTexCoord;

uniform sampler2D uTexture;
uniform vec3 uTint;

void main()
{
	if(uTint.x > 0.0 || uTint.y > 0.0 || uTint.z > 0.0){

		gl_FragColor = texture2D(uTexture, v_fragTexCoord) * vec4(uTint, 1.0);

	}else{

		gl_FragColor = texture2D(uTexture, v_fragTexCoord);

	}
}