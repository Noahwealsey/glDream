#include"vertexArray.h"

#include <GL/glew.h>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
}
VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::bind()const {
	glBindVertexArray(m_RendererID);
}
void VertexArray::unbind()const {
	glBindVertexArray(0);
}

void VertexArray::addBuff(const VertexBuffer& vb, const VertexBufferLayout& vbl){
	
	bind();
	vb.bind();
	const auto& elements = vbl.getElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalised, vbl.getStride(), (const void*)offset);
		offset += element.count * VertexBufferelements::GetSizeofType(element.type);

	}
}